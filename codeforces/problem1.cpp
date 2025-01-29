#include <iostream>
using namespace std;

int lcm(int a, int b)
{
    int tempA = a;
    int tempB = b;

    if (b % a == 0)
    {
        return b * (b / a);
    }
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return tempA / a * tempB;
}

int main()
{
    int totalCases;
    cin >> totalCases;

    while (totalCases-- > 0)
    {
        int a, b;
        cin >> a >> b;
        cout << lcm(a, b) << endl;
    }
    return 0;
}