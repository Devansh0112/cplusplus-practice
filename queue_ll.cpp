#include <iostream>

using namespace std;

class QNode
{
public:
    int data;
    QNode *next;

    QNode() { next = nullptr; }
};

class Queue
{
public:
    QNode *front, *rear;
    int size_of_q;

    Queue()
    {
        front = rear = nullptr;
        size_of_q = 0;
    }

    void enQueue(int val)
    {
        size_of_q++;
        QNode *new_data = new QNode();
        new_data->data = val;

        if (front == nullptr)
        {
            front = rear = new_data;
        }
        else
        {
            rear->next = new_data;
            rear = new_data;
        }
    }

    void deQueue()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty!";
            return;
        }

        size_of_q--;
        cout << "Deleted the element : " << front->data << endl;

        QNode *temp = front;

        front = front->next;

        delete temp;

        return;
    }

    void displayQueue()
    {
        if (front == nullptr) {
            cout << "No element in the Queue!" << endl;
            return;
        }
        QNode *temp = this->front;
        while (temp != nullptr)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }

        cout << endl;

        delete temp;
    }

    int get_front()
    {
        return front->data;
    }

    bool isEmpty()
    {
        return front == nullptr ? true : false;
    }

    int size()
    {
        return size_of_q;
    }

    void clear_queue()
    {
        size_of_q = 0;

        QNode *current = front;
        QNode *next;

        while (current != nullptr)
        {
            next = current->next;
            delete current;
            current = next;
        }

        front = rear = nullptr;
    }
};

int main()
{

    Queue q;

    q.enQueue(23);
    q.enQueue(12);
    q.enQueue(34);
    q.enQueue(45);
    q.enQueue(56);

    q.displayQueue();

    q.deQueue();
    q.deQueue();

    q.displayQueue();

    q.enQueue(23);
    q.enQueue(12);

    q.displayQueue();

    q.clear_queue();

    q.displayQueue();

    return 0;
}