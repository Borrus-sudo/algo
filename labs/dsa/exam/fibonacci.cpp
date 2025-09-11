#include <iostream>
using namespace std;

int fibo(int num)
{
    if (num == 0 || num == 1)
        return num;
    return fibo(num - 1) + fibo(num - 2);
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
 
    int res = fibo(num);
    cout << "The fibonacci of the number " << num << " is " << res;
    return 0;
}