#include <iostream>

using namespace std;

class Base
{
public:
    Base() {}

    virtual void print() { cout << "Base"; }
};

class Derived : public Base
{
public:
    Derived() {}
    void print() override { cout << "Derived"; }
};

int main()
{
    try
    {
        try
        {
            throw Derived{};
        }
        catch (Base &b)
        {
            cout << "Caught base B which is actually a ";
            b.print();
            cout << endl;
            throw b;
        }
    }
    catch (Base &b)
    {
        cout << "Caught base B which is actually a ";
        b.print();
        cout << endl;
    }
    return 0;
}