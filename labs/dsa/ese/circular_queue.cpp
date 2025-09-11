struct Node
{
    int val;
    Node *next = nullptr;
    Node(int val) : val(val) {}
};

class CircularQueue
{
    int queue[5];
    int front = -1;
    int rear = -1;
    bool isEmpty()
    {
        return front == -1;
    }
    bool isFull()
    {
        return (rear + 1) % 5 == front;
    }
    void enqueue(int val)
    {
        if (isEmpty())
        {
            front = 0;
            rear = 0;
            queue[front] = val;
        }
        else
        {
            if (isFull())
            {
                throw "";
            }
            else
                queue[++rear % 5] = val;
        }
    }
    void dequeue()
    {
        if (isEmpty())
        {
            throw "";
        }
        else
        {
            bool lenOne = front % 4 == rear % 4;
            queue[front % 4] = -1;
            front++;
            if (lenOne)
                front = rear = -1;
        }
    }
    int front()
    {
        if (isEmpty())
            throw "";
        return queue[front];
    }
};