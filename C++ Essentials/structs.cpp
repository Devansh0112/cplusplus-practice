#include<iostream>
#include<cstdint>

using  points_t = uint32_t;
using score_t = uint64_t;

using std::cout;

struct p {
    points_t a;
    score_t b;
};


int main()
{
    p obj = {4, 6};

    cout << obj.a << " and " << obj.b;
}