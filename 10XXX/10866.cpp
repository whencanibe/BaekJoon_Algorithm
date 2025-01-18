#include <iostream>
#include <string>

using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;

    Node(int data) : data(data), prev(nullptr) ,next(nullptr) {}
};

class Deque
{
private:
    Node *front;
    Node *back;
    int size;

public:
    Deque() : front(nullptr), back(nullptr), size(0) {};
    ~Deque(){
        while(front != nullptr){
            Node *tmp = front;
            front = front->next; // while의 조건을 !empty로하면 마지막에 front가 nullptr이기 때문에 nullptr 접근으로 에러가 생김
            delete tmp;
        }
    };

    void pushFront(int X)
    {   
        Node *newNode = new Node(X);
        if (empty())
        {
            front = back = newNode;
        }
        else
        {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        size++;
    }

    void pushBack(int X)
    {   
        if (empty()){
            Node *newNode = new Node(X);
            front = newNode;
            back = newNode;
            size++;
            return ;
        }
        Node *newNode = new Node(X);
        newNode->prev = back;
        back->next = newNode;
        back = newNode;
        size++;
    }

    int popFront()
    {
        if (empty())
        {
            return -1;
        }
        Node *tmp = front;
        int value = tmp->data;
        front = front->next;

        if (front)
        {
            front->prev = nullptr;
        }
        else
        {
            back = nullptr; // Deque가 비게 되었을 때 back도 nullptr로 설정
        }

        delete tmp;
        size--;
        return value;
    }

    int popBack(){
        if (empty())
        {
            return -1;
        }
        Node *tmp = back;
        int value = tmp->data;
        back = back->prev;

        if (back)
        {
            back->next = nullptr;
        }
        else
        {
            front = nullptr; // Deque가 비게 되었을 때 front도 nullptr로 설정
        }

        delete tmp;
        size--;
        return value;
    }

    int empty()
    {   
        return size == 0 ? 1 : 0;
    }

    int getSize(){
        return size;
    }

    int getFront(){
        return empty() ? -1 : front->data;
    }

    int getBack(){
        return empty() ? -1 : back->data;
    }
};

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Deque dq;
    int N;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string command;
        cin >> command;

        if (command == "push_front")
        {
            int x;
            cin >> x;
            dq.pushFront(x);
        } else if (command == "push_back")
        {
            int x;
            cin >> x;
            dq.pushBack(x);
        }
        else if (command == "pop_front")
        {
            cout << dq.popFront() << endl;
        }
        else if (command == "pop_back")
        {
            cout << dq.popBack() << endl;
        }
        else if (command == "size")
        {
            cout << dq.getSize() << endl;
        }
        else if (command == "empty")
        {
            cout << dq.empty() << endl;
        }
        else if (command == "front")
        {
            cout << dq.getFront() << endl;
        }
        else if (command == "back")
        {
            cout << dq.getBack() << endl;
        }
    }

    return 0;
}
