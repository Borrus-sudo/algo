#include <iostream>
#include <vector>
using namespace std;

class A
{
public:
    A()
    {
        cout << "A created" << endl;
    }

    A(const A &other)
    {
        cout << "A copied" << endl;
    }
    A(const A &&move)
    {
        cout << "A moved" << endl;
    }

    ~A()
    {
        cout << "A destroyed" << endl;
    }
};

int main()
{
    vector<A> places;
    places.reserve(2);
    A a1;
    places.push_back(move(a1));
    places.push_back(A());
    return 0;
}