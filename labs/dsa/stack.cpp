#include <iostream>

class Stack
{
private:
    int arr[100];
    int top;

public:
    Stack() { top = -1; }

    void push(int value)
    {
        if (top >= 99)
        {
            std::cout << "Stack Overflow! Cannot push " << value << std::endl;
            return;
        }
        arr[++top] = value;
        std::cout << value << " pushed onto stack." << std::endl;
    }

    int pop()
    {
        if (top < 0)
        {
            std::cout << "Stack Underflow! No elements to pop." << std::endl;
            return -1;
        }
        int poppedValue = arr[top--];
        std::cout << "Popped: " << poppedValue << std::endl;
        return poppedValue;
    }

    void display()
    {
        if (top < 0)
        {
            std::cout << "Stack is empty!" << std::endl;
            return;
        }
        std::cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.display();

    stack.pop();
    stack.display();

    return 0;
}
