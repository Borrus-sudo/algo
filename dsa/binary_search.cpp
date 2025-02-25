#include <iostream>

using namespace std;

int search(int arr[], int size, int target)
{
    int left = 0, right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            return mid; // Target found
        }
        else if (arr[mid] < target)
        {
            left = mid + 1; // Search right half
        }
        else
        {
            right = mid - 1; // Search left half
        }
    }

    return -1; // Target not found
}

int main()
{
    int arr[] = {2, 3, 4, 10, 40};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    int result = search(arr, size, target);
    cout << result;
    return 0;
}
