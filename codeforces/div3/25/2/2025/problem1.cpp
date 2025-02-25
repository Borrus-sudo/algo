#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int lines;
    cin >> lines;
    while (lines-- > 0)
    {
        int n, k, p;
        cin >> n;
        cin >> k;
        cin >> p;
        int res = ceil((float)abs(k) / p);
        cout << ((res <= n) ? res : -1) << endl;
    }
    return 0;
}