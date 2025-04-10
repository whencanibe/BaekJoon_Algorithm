#include <iostream>

class MyStack
{
private:
    struct Node
    {
        int data;
        Node *down;
        Node(int _data) : data(_data), down(nullptr) {};
    };

    Node *top;
    int size;

public:
    MyStack()
    {
        top = nullptr;
        size = 0;
    }

    ~MyStack()
    {
        while(!isEmpty()){
            pop();
        }
    }

    bool isEmpty()
    {
        return size == 0 ? 1 : 0;
    }

    void push(int data)
    {
        Node *newNode = new Node(data);
        newNode->down = top;
        top = newNode;
        size++;
    }

    int pop()
    {   
        if(isEmpty()){
            exit(1);
        }
        Node* tmp = top;
        int result = tmp->data;

        top = tmp->down;
        size--;
        
        delete tmp;
        return result;
    }
};

int main(int argc, char const *argv[])
{
    int K;
    scanf("%d",&K);
    MyStack stack = MyStack();

    for (int i = 0 ; i < K ; i++){
        int input;
        scanf("%d", &input);
        if (input == 0){
            stack.pop();
        } else{
            stack.push(input);
        }
    }
    int result = 0;
    while(!stack.isEmpty()){
        result += stack.pop();
    }
    printf("%d",result);
    return 0;
}
