#include <iostream>

using namespace std;

class Queue {

    public:
    int front, rear, capacity;
    int queue[5];

    Queue(int cap) {
        front = 0;
        rear = 0;
        capacity = cap;
    }

    void Enqueue(int data)
    {
        if (capacity == rear)
        {
            printf("\n Queue is full \n");
            return;
        }
        else 
        {
            queue[rear] = data;
            rear++;
        }
    }

    void Dequeue()
    {
        if (front == rear)
        {
            printf("\nQueue is Empty\n");
            return;
        }
        else 
        {
            for (int i=0; i < rear - 1; i++)
            {
                queue[i] = queue[i+1];
            }

            rear--;
        }

        return;
    }

    void Display()
    {

        cout<<"We are in Display function!"<<endl;
        int i;
        if (front == rear)
        {
            printf("\n Queue is empty\n");
            return;
        }

        for (i=front; i<rear; i++)
        {
            cout<<queue[i] << "\t";
        }

        cout << endl;

        return;
    }

};

int main()
{
    Queue q(5);

    q.Enqueue(5);
    q.Enqueue(6);
    q.Enqueue(7);
    q.Enqueue(23);
    q.Enqueue(45);

    q.Display();
    q.Dequeue();
    q.Display();

    q.Enqueue(34);
    
    q.Display();


    return 0;
}