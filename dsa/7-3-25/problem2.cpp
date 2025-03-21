#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T val;
    Node *prev = nullptr;
    Node(T val) : val(val) {};
};

template <typename T>
class Stack
{
    Node<T> *head = nullptr;

public:
    void push(T val)
    {
        Node<T> *entry = new Node<T>(val);
        entry->prev = head;
        head = entry;
    }
    void pop()
    {
        if (head != nullptr)
        {
            Node<T> *toDel = head;
            head = head->prev;
            delete toDel;
        }
    }
    T peek()
    {
        if (head != nullptr)
            return head->val;
        else
            throw "Error: stack empty";
    }
};

int main()
{
    Stack<int> *s = new Stack<int>();
    s->push(10);
    s->push(20);
    cout << s->peek();
}