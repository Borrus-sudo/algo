#include <iostream>
using namespace std;

template <typename T, int S>
class Stack
{
    T arr[S];
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
    Stack<int, 10> s;
    s.push(10);
    s.push(20);
    cout << s.peek();
    return 0;
}