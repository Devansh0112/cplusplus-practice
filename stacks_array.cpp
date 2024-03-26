#include<iostream>

using namespace std;

#define MAX 1000

class stack {
    int top;
    public:
        int arr[MAX];

        stack()
        {
            top = -1;
        }

        void push(int val)
        {
            if (top >= MAX - 1){
                cout<<"stack overflow" << endl;
            }
            else 
            {
                arr[++top] = val;
            }
        }

        int pop()
        {
            if (this->isEmpty())
            {
                cout<<"stack underflow"<<endl;
                return 0;
            }
            else
            {
                int val = arr[top--];
                return val;
            }
        }

        void peek()
        {
            if(this->isEmpty())
            {
                cout << "No element in stack" << endl;
            }
            else 
            {
                int val = arr[top];
                cout << "the value at top is : " << val << endl;
            }
        }

        bool isEmpty()
        {
            if (top == -1) return true;
            else return false;
        }
};


int main()
{
    class stack s; 
    s.push(10); 
    s.push(20); 
    s.push(30); 
    cout << s.pop() << " Popped from stack\n"; 
    
    //print top element of stack after popping 
    s.peek();
    
    //print all elements in stack : 
    cout <<"Elements present in stack : " << endl; 
    while(!s.isEmpty()) 
    { 
        // print top element in stack 
        s.peek();
        // remove top element in stack 
        s.pop(); 
    } 
  
    return 0; 
}