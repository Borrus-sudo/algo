struct Node
{
    int val;
    Node *next = nullptr;
    Node *prev = nullptr;
    Node(int val, Node *next = nullptr, Node *prev = nullptr) : val(val), next(next), prev(prev) {}
};

class DoubleLL {
    Node *head = nullptr;
    Node *rear = nullptr;
        
};