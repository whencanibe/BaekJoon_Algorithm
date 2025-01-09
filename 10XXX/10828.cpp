#include <iostream>

using namespace std;

class Stack
{
private:
    int* stack;
    int top;
    int capacity;

    void resize(){
        int newCapacity = capacity * 2;
        int *newStack = new int[newCapacity];

        //기존 데이터 복사
        for (int i = 0 ; i < capacity ; i++){
            newStack[i] = stack[i];
        }
        // 기존 메모리 해제
        delete[] stack;
        stack = newStack;
        capacity = newCapacity;
    }
public:
    Stack(int initialCapacity = 4) : top(-1), capacity(initialCapacity) {
        stack = new int[initialCapacity];
    };
    ~Stack(){
        delete[] stack;
    };

    void push(int X){
        if (top >= capacity - 1) resize();
        stack[++top] = X;
    }

    void pop(){
        if (top < 0){
            cout << -1 << endl;
            return ;
        }
        cout << stack[top--] << endl;
    }

    void size(){
        cout << top + 1 << endl;
    }

    void empty(){
        if ( top < 0) cout << 1 << endl;
        else cout << 0 << endl;
    }

    void getTop(){
        if (top < 0){
            cout << -1 << endl;
            return ;
        }
        cout << stack[top] << endl;
    }
};



int main(int argc, char const *argv[])
{
    Stack myStack;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++){
        string command;
        cin >> command;

        if (command == "push") {
            int x;
            cin >> x;
            myStack.push(x);
        } else if (command == "pop") {
            myStack.pop();
        } else if (command == "size") {
            myStack.size();
        } else if (command == "empty") {
            myStack.empty();
        } else if (command == "top") {
            myStack.getTop();
        }

    }

    return 0;
}
