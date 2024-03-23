#include<iostream>

using namespace std;

class A
{
    private :
        int m_x;
    public :
        A(int x) : m_x{x}
        {
            if (x <= 0)
            {
                throw 1;
            }
        }
};

class B : public A
{
    public : 
        B(int x) try : A{x}
        {
        }
        catch(...)
        {
            cerr << "Excepton caught\n";
            throw;
        }
        

};


int main()
{
    try {
        B b{0};
    }
    catch(int)
    {
        cout<<"oops"<<endl;
    }
    return 0;
}