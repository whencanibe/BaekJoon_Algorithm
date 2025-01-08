#include <iostream>
#include <vector>
#include <algorithm>

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

        // 기존 메모리 해제
    }
public:
    Stack(int initialCapacity = 4) : top(-1), capacity(initialCapacity) {
        stack = new int[initialCapacity];
    };
    ~Stack(){
        delete[] stack;
    };
};



int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
