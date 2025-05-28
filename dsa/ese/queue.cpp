struct Node
{
    int val;
    Node *next;
    Node *prev;
    Node(int val, Node *next = nullptr, Node *prev = nullptr) : val(val), next(next), prev(prev) {};
};

class Queue
{
    Node *front = nullptr;
    Node *rear = nullptr;
    bool isEmpty()
    {
        return front == nullptr;
    }
    void enqueue(int val)
    {
        Node *newElem = new Node(val);
        if (isEmpty())
        {
            front = newElem;
            rear = newElem;
        }
        else
        {
            rear->next = newElem;
            rear = rear->next;
        };
    }
    void dequeue()
    {
        if (isEmpty())
            throw "";
        // not empty
        Node *temp = front;
        if (front == rear)
        {
            front = rear = nullptr;
        }
        else
        {
            front = front->next;
        }
        delete temp;
    }

    int front()
    {
        if (isEmpty())
            throw "Fucking empty";
        return front->val;
    }
};