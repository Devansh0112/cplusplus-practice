#include<iostream>
#include<typeinfo>

using namespace std;

int main()
{
    const char string[] = "some text goes here";

    auto *p = string;

    cout << typeid(*p).name();

    cout << '-';

    for(auto *p=string; *p; p++)
    {
        cout << *p << '-';
    }

    return 0;
}