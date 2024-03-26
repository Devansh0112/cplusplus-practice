#include<iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;

    s.push(5);
    s.push(4);
    s.push(34);
    s.push(23);
    s.push(12);

    while(!s.empty())
    {
        cout << s.top() <<endl;

        s.pop();
    }

    return 0;
}