#include <vector>
using namespace std;

int binary_search_algo(vector<int> &arr, int ref)
{
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == ref)
            return mid;
        else if (arr[mid] > ref)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
};
