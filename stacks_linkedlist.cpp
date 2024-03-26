#include <iostream>

using namespace std;

class Node
{
public:
    int val;
    Node *next;
};

class Stack
{
    Node *head;

public:
    Stack(int val)
    {
        Node *node = new Node();
        node->val = val;
        head = node;
    }

    void push(int val)
    {
        Node *new_val = new Node();
        new_val->val = val;

        if (head == nullptr)
        {
            head = new_val;
        }
        else
        {
            Node *temp = head;

            while (temp->next != nullptr)
            {
                temp = temp->next;
            }

            temp->next = new_val;
        }
    }

    void pop()
    {
        if (head == nullptr)
        {
            cout << "stack underflow" << endl;
        }
        else
        {
            Node *temp = head;
            Node* cur = temp;
            while (temp->next != nullptr)
            {
                cur = temp;
                temp = temp->next;
            }

            cout << "we are going to pop the element : " << temp->val << endl;

            cur->next = nullptr;
            delete temp;
        }
    }

    void peek()
    {
        if (head == nullptr)
        {
            cout << "No element in stack" << endl;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }

            cout << "The top element is : " << temp->val << endl;
        }
    }

    void print()
    {
        Node *temp = head;
            while (temp != nullptr)
            {
                cout << temp->val << endl;
                temp = temp->next;
            }
    }
};

int main()
{
    Stack *s = new Stack(5);

    s->push(23);
    s->push(35);
    s->push(98);
    s->print();

    s->peek();

    s->pop();

    s->print();

    return 0;
}