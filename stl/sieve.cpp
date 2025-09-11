#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int N = 100;
    vector<bool> is_prime(N + 1, true);
    for (int i = 2; i * i <= N; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 1; i < N + 1; i++)
        if (is_prime[i])
            cout << i << endl;
    return 0;
}