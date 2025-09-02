#include <array>

#include <algorithm>

#include <iostream>

using namespace std;

int main()
{
    array<int, 5> arr{1, 2, 3, 4, 5};
    int target = 3;
    int pos = -1;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == target)
        {
            pos = i;
            break;
        }
    }

    cout << pos << endl;

    return 0;
}