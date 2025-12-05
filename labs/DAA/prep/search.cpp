#include <iostream>
#include <vector>
using namespace std;

int interpolationSearch(vector<int>& arr, int val) {
    int low = 0;
    int high = arr.size();
    while (val >= arr[low] && val <= arr[high] && low <= high) {
        int probe = (val - arr[low]) / (arr[high] - arr[low]) * (high - low);
        if (arr[probe] == val) {
            return probe;
        } else if (arr[probe] > val) {
            high = probe - 1;
        } else
            low = probe + 1;
    }
    return -1;
}

int binarySearch(vector<int>& arr, int val) {
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == val) {
            return mid;
        } else if (arr[mid] > val) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int main() {
    return 0;
}