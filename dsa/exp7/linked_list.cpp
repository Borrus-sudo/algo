#include <iostream>
using namespace std;

struct Node
{
    Node *next;
    int val;
    Node(int val) : next(nullptr), val(val) {}
};

class LinkedList
{
    Node *front = nullptr;
    Node *back = nullptr;

public:
    void insertBack(int val)
    {
        if (back == nullptr)
        {
            back = new Node(val);
            front = back;
        }
        else
        {
            back->next = new Node(val);
            back = back->next;
        }
    }

    void insertFront(int val)
    {
        if (front == nullptr)
        {
            front = new Node(val);
            back = front;
        }
        else
        {
            Node *temp = new Node(val);
            temp->next = front;
            front = temp;
        }
    }

    void editElement(int oldVal, int newVal)
    {
        Node *iter = front;
        while (iter)
        {
            if (iter->val == oldVal)
            {
                iter->val = newVal;
                return;
            }
            else
            {
                iter = iter->next;
            }
        }
    }

    void deleteElement(int val)
    {
        Node *iter = front;
        Node *prev = nullptr;
        while (iter)
        {
            if (iter->val == val)
            {
                // delete this element
                if (prev)
                    prev->next = iter->next;

                if (iter == front)
                    front = iter->next;

                if (iter == back)
                    back = prev;

                delete iter;
                return;
            }

            prev = iter;
            iter = iter->next;
        }
    }

    int search(int val)
    {
        int idx = -1;
        Node *iter = front;
        while (iter)
        {
            idx++;
            if (iter->val == val)
                return idx;
            iter = iter->next;
        }

        cout << "Not found" << endl;
        return -1;
    }

    void printList()
    {
        Node *iter = front;
        while (iter)
        {
            cout << iter->val << endl;
            iter = iter->next;
        }
        return;
    }
};

int main()
{
    LinkedList list;

    cout << "Inserting at back: 10, 20\n";
    list.insertBack(10);
    list.insertBack(20);

    cout << "Inserting at front: 5\n";
    list.insertFront(5);

    cout << "Current list: " << endl;
    list.printList();

    cout << "Searching for 10: Index = " << list.search(10) << endl;
    cout << "Editing 10 -> 15\n";
    list.editElement(10, 15);
    list.printList();

    cout << "Deleting 15\n";
    list.deleteElement(15);
    list.printList();

    cout << "Deleting 5\n";
    list.deleteElement(5);
    list.printList();
    cout << "Deleting 20\n";
    list.deleteElement(20);
    list.printList();

    return 0;
}