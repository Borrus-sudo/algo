#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int lines;
    cin >> lines;
    while (lines-- > 0)
    {
        int n;
        string s;
        cin >> n;
        cin >> s;
        long long underscores = 0;
        long long dashes = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '_')
                underscores++;
            else
                dashes++;
        }
        long long maxPossiblities;
        if (dashes & 1)
        {
            maxPossiblities = dashes / 2 * (dashes / 2 + 1);
        }
        else
        {
            maxPossiblities = pow(dashes / 2, 2);
        };
        cout << (maxPossiblities * underscores) << endl;
    }
    return 0;
}