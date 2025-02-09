// PASS
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int lines;
    cin >> lines;
    while (lines-- > 0)
    {
        string input;
        cin >> input;
        bool log = true;
        for (int i = 0; i < input.length() - 1; i++)
        {
            if (input[i] == input[i + 1])
            {
                cout << 1 << endl;
                log = false;
                break;
            }
        }
        if (log)
            cout << input.size() << endl;
    }
    return 0;
}