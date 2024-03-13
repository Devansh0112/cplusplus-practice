#include<iostream>

using namespace std;

void function()
{
    throw -1; // the exception thrown here will be caught by the catch where this function is called
}

void funcD() {
    throw -1;
}

void funcC()
{
    try {
        funcD();
    }
    catch(double)
    {
        cout << "C caught the double exception" << endl;
    }
}

void funcB() {
    try {
        funcC();
    } catch (double)
    {
        cout << "B caught the double exception" << endl;
    }
    try {

    } catch (int)
    {
        cout << "B caught the int exception" << endl;
    }
}

void funcA()
{
    try {
        funcB();
    } catch (int) 
    {
        cout << "A caught the int exception" << endl;
    }
}

int main()
{
    try {
        funcA();
    }
    catch (int) 
    {
        cout << "Main block caught the exception"<<endl;
    }
    // int age = 15;
    // try {
    //     function();
    // } catch (...)  // this catches any kind of exception
    // {
    //     cout << "Bad input " << endl;
    // }
    return 0;
}