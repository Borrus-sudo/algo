#include <iostream>
using namespace std;

int factorial(int num)
{
    if (num == 0)
        return 1;
    return num * factorial(num - 1);
}

int main()
{
    cout << "Enter a number: ";
    int num;
    cin >> num;
    
    
    if (num < 0)
    {
        cout << "Invalid input" << endl;
        return 1;
    }

    int res = factorial(num);
    cout << "The factorial of the number " << num << " is " << res;
    return 0;
}