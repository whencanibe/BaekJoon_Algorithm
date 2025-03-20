#include <iostream>
#include <string>
using namespace std;

class MyStack
{
private:
    struct Node
    {
        char data;
        Node *next;

        Node(char _data) : data(_data), next(nullptr) {}
        ~Node() {}
    };
    Node *head;

public:
    MyStack() : head(nullptr) {}

    ~MyStack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    bool isEmpty()
    {
        return head == nullptr ? true : false;
    }

    char pop()
    {
        if (isEmpty())
        {
            return -1;
        }

        char result = head->data;
        Node *tmp = head;
        head = head->next;
        delete tmp;
        return result;
    }

    void push(char data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
};

void isVps()
{
    string input;
    MyStack stack = MyStack();

    cin >> input;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == '(')
        {
            stack.push(input[i]);
        }
        else if (input[i] == ')')
        {   
            while(true)
            {   
                char tmp = stack.pop();
                {
                    if (tmp == -1)
                    {
                        cout << "NO" << endl;
                        return ;
                    }
                }
                if(tmp == '(') break;
            }
        }
    }

    if (!stack.isEmpty())
    {
        cout << "NO" << endl;
        return ;
    }

    cout << "YES" << endl;
}

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    cin.ignore();

    for (int i = 0; i < N; i++)
    {
        isVps();
    }
    return 0;
}
