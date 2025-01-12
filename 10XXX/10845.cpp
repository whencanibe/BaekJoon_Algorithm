#include <iostream>
#include <string>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x) : data(x), next(nullptr) {}
};

class Queue
{
private:
    Node *front;
    Node *back;
    int size;

public:
    Queue() : front(nullptr), back(nullptr), size(0) {}
    ~Queue()
    {
        Node *temp;
        while (front != nullptr)
        {
            temp = front;
            front = front->next;
            delete temp;
        }
        // while (!empty()) {
        //     pop();
        // }
        // delete front;
        // delete back;
    }
    void push(int X)
    {
        Node *newNode = new Node(X);
        if (empty())
        {
            front = back = newNode;
        }
        else
        {
            back->next = newNode;
            back = newNode;
        }
        size++;
    }

    void pop()
    {
        if (empty())
        {
            cout << -1 << endl;
            return;
        }
        cout << front->data << endl;
        Node *temp = front;
        front = front->next;
        delete temp;
        size--;
        if (size == 0)
        {
            back = nullptr;
        }
    }

    int getSize()
    {
        return size;
    }

    int empty()
    {
        if (size == 0)
            return 1;

        return 0;
    }

    int getFront()
    {
        if (empty())
            return -1;
        return front->data;
    }

    int getBack()
    {
        if (empty())
            return -1;
        return back->data;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Queue q;
    int N;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string command;
        cin >> command;

        if (command == "push")
        {
            int x;
            cin >> x;
            q.push(x);
        }
        else if (command == "pop")
        {
            q.pop();
        }
        else if (command == "size")
        {
            cout << q.getSize() << endl;
        }
        else if (command == "empty")
        {
            cout << q.empty() << endl;
        }
        else if (command == "front")
        {
            cout << q.getFront() << endl;
        }
        else if (command == "back")
        {
            cout << q.getBack() << endl;
        }
    }
    return 0;
}
