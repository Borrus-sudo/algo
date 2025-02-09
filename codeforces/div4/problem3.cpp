/** FAIL */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    int lines;
    cin >> lines;
    while (lines-- > 0)
    {
        int n, m;
        vector<int> toSort;
        int subtractor;
        cin >> n;
        cin >> m; // m is gonna be one
        int sample_len_n = n;
        while (sample_len_n-- > 0)
        {
            int num;
            cin >> num;
            toSort.push_back(num);
        }
        cin >> subtractor;
        bool failure = false;
        unordered_map<int, bool> dont;
        for (int i = 0; i < n; i++)
        {
            // increasing order
            bool firstCheck = i != 0 ? toSort[i] >= toSort[i - 1] : true;
            bool secondCheck = i != n - 1 ? toSort[i] <= toSort[i + 1] : true;
            if (firstCheck && secondCheck)
            {
                // move on
                continue;
            }
            // a man can hope
            toSort[i] = subtractor - toSort[i];
            dont[i] = true;
        }
        for (int i = 0; i < n; i++)
        {
            bool firstCheck = i != 0 ? toSort[i] >= toSort[i - 1] : true;
            bool secondCheck = i != n - 1 ? toSort[i] <= toSort[i + 1] : true;
            if (firstCheck && secondCheck)
            {
                // move on
                continue;
            }
            // a man can hope
            if (!dont[i])
            {
                toSort[i] = subtractor - toSort[i];
            }

            firstCheck = i != 0 ? toSort[i] >= toSort[i - 1] : true;
            secondCheck = i != n - 1 ? toSort[i] <= toSort[i + 1] : true;
            if (firstCheck && secondCheck)
            {
                // move on
                continue;
            }
            else
            {
                failure = true;
                break;
            }
        }
        if (failure)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}