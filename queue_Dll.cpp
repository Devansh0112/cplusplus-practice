#include <iostream>

using namespace std;

class QNode
{
public:
    int data;
    QNode *next;
    QNode *prev;

    QNode() {
        next = prev = nullptr;
    }
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

    void insertRear(int val)
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

    void insertFront(int val)
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
            new_data->next = front;
            front = new_data;
        }
    }

    void deleteFront()
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

    void deleteRear()
    {
        if (rear == front)
        {
            cout << "Queue is empty!"<<endl;
            return;
        }
        
        size_of_q--;
        cout << "Deleted the element : " << rear->data << endl;

        QNode *temp = front;

        while (temp->next != rear)
        {
            temp = temp->next;
        }

        rear = temp;
        temp = temp->next;

        rear->next=nullptr;
    
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

    int get_rear()
    {
        return rear->data;
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

    q.insertFront(23);
    q.insertFront(12);
    q.insertFront(34);
    q.insertRear(45);
    q.insertRear(56);

    q.displayQueue();

    q.deleteFront();
    q.deleteRear();

    q.displayQueue();

    q.insertFront(155);
    q.insertRear(345);

    q.displayQueue();

    q.clear_queue();

    q.displayQueue();

    return 0;
}