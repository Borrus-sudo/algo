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
    Node *head = nullptr;
    void push(T val)
    {
        Node *entry = new Node(val);
        entry->prev = head;
        head = entry;
    }
    void pop()
    {
        if (head != nullptr)
        {
            Node *toDel = head;
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

int main() {}