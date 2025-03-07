#include <iostream>
using namespace std;

template <typename T, int S>
class Stack
{
    T arr[s];
    int idx = 0;

public:
    void push(T elem)
    {
        arr[idx++] = elem;
    }
    void pop()
    {
        if (idx > 0)
            idx--;
    }

    T peek()
    {
        if ((idx) > 0)
            return arr[idx - 1];
        else
            throw "Error: Can't pop an empty stack";
    }
};

int main()
{
    return 0;
}