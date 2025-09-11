#include <array>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

int main()
{
    array<int, 5> arr{1, 2, 3, 4, 5};
    int left = 0;
    int right = arr.size() - 1;
    int pos = -1;
    int target = 4;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            pos = mid;
            break;
        }
        else if (arr[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << (pos) << endl;

    return 0;
}