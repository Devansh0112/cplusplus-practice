#include<iostream>
#include<queue>

using namespace std;

void showq(queue<int> q)
{
    queue<int> g = q;
    while (!g.empty())
    {
        cout << g.front() << endl;
        g.pop();
    }
}

int main()
{
    queue<int> gquiz;
    gquiz.push(20);
    gquiz.push(30);
    gquiz.push(50);

    cout << "The queue is : \n";

    showq(gquiz);

    cout << "Queue size : " << gquiz.size() << endl;
    cout<< "Front element : " << gquiz.front() << endl;
    cout << "Back element : " << gquiz.back() << endl;

    cout << "Popping element : " << gquiz.front() << endl;
    gquiz.pop();

    cout << "The queue is : \n";
    showq(gquiz);



    return 0;
}