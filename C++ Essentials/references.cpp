#include<iostream>

using namespace std;

int main() {
    int x = 3;
    int& y = x;
    const int& z = x;

    cout << "Value of x is : " << x << endl;
    cout << "Y is reference to x : " << y << endl;

    y = 43;

    cout << "value of x is also changed : " << x << endl;

    // That is why referencing always use const

    // z = 12; // this line will not compile and give error

    return 0;
}