struct Node
{
    int val;
    Node *next;
    Node *prev;
    Node(int val, Node *next = nullptr, Node *prev = nullptr) : val(val), next(next), prev(prev) {}
};

class CircularLL
{
    Node *head = nullptr;
    bool isEmpty()
    {
        return head == nullptr;
    }
    void insertBegin(int val)
    {
        //
        if (isEmpty())
        {
            head = new Node(val);
            head->next = head;
        }
        else
        {
            Node *elem = new Node(val);
            elem->next = head;
            Node *iter = head;
            while (iter->next != head)
                iter = iter->next;
            Node *rear = iter->next;
            head = elem;
            rear->next = head;
        }
    }
    void insertAtEnd(int val)
    {
        if (isEmpty())
        {
            head = new Node(val);
            head->next = head;
        }
        else
        {
            Node *iter = head;
            while (iter->next != head)
            {
                iter = iter->next;
            }
            Node *rear = iter->next;
            Node *elem = new Node(val);
            rear->next = elem;
            elem->next = head;
        }
    }
    void popBegin()
    {
        if (isEmpty())
            throw "";
        else
        {
            Node *temp = head;
            Node *iter = head;
            while (iter->next != head)
            {
                iter = iter->next;
            }
            Node *rear = iter->next;
            rear = head->next;
            head = head->next;
            delete temp;
        }
    }
    void popEnd()
    {
        if (isEmpty())
            throw "";
        else
        {
            Node *iter = head;
            while (iter->next && iter->next->next != head)
            {
                iter = iter->next;
            }
            Node *rear = iter->next;


        }
    }
};