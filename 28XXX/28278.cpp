#include <iostream>

class MyStack{
private:
    struct Node
    {
        int data;
        Node* below;

        Node(int _data) : data(_data), below(nullptr) {}
    };
    Node* top;
    int size;
    
public:
    MyStack() : top(nullptr), size(0) {}
    ~MyStack(){
        while(!isEmpty()){
            pop();
        }
    }
    int isEmpty(){
        if (top == nullptr) return 1;
        return 0;
    }

    void push(int data){
        Node* newNode = new Node(data);
        newNode->below = top;
        top = newNode;
        size++;
    }

    int pop(){
        if(isEmpty()){
            return -1;
        }
        Node* tmp = top;
        int result = tmp->data;
        top = tmp->below;
        delete tmp;
        size--;
        return result;
    }

    int getSize(){
        return size;
    }

    int getTop(){
        if(isEmpty()){
            return -1;
        }

        return top->data;
    }
};

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    MyStack stack = MyStack();

    for(int i = 0 ; i < N ; i++){
        int cmd;
        scanf("%d", &cmd);
        if(cmd == 1){
            int data;
            scanf("%d", &data);
            stack.push(data);
        } else if (cmd == 2){
            printf("%d\n", stack.pop());
        } else if (cmd == 3){
            printf("%d\n", stack.getSize());
        } else if (cmd == 4){
            printf("%d\n", stack.isEmpty());
        } else if (cmd == 5){
            printf("%d\n", stack.getTop());
        }
    }
    return 0;
}
