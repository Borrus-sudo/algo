#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int lines;
    cin >> lines;
    while (lines-- > 0)
    {
        int n, x;
        cin >> n;
        while (--n >= 0) {
            cout << (n == 0 ? x : 0);
        };
        cout << endl;
    }
    return 0;
}