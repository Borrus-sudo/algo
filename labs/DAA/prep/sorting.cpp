#include <algorithm>
#include <vector>
using namespace std;

/**
 * MECHANISM:
 * It works by building a sorted array from the START. Every iteration i_th iteration puts the
 * (i - 1)_th element in the correct position
 * Demo :
 * [3, 2, 1, 1]
 * [2, 3, 1, 1]
 * [1, 3, 2, 1]
 * [1, 2, 3, 1]
 * [1, 1, 3, 2]
 * [1, 1, 2, 3]
 *
 * As one can see the stability is being preserved
 * For proving time complexity, worse case, is obviously reverse sorted array.
 * Takes   2 * (n - 1) + 2 * (n - 2) + ... + 2
 *       = 2 *  ( (n - 1) + (n - 2) + (n - 3) + (n - 4) + ... + 1 )
 *       = 2  * n * (n - 1) / 2
 *       = n * (n - 1)
 * Therefore Time Complexity: takes O(n^2)
 *           Space Complexity: O(1) or O(n), depends on whether you mutate the input array or not
 *           Stable: NO
 *              - Example : [3, 4, 3, 2]
 *                          --> Compare (3, 4)
 *                          --> Compare (3, 3)
 *                          --> Compare (3, 2)
 *                                  --> Swap(3, 2) : BREAKS STABILITY!
 *
 *
 *
 */
void selection_sort(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

/**
 * MECHANISM:
 * It works by building a sorted array from the END. Every iteration i_th iteration puts the
 * (n - i + 1)_th element in the correct position
 * Demo :
 * [3, 2, 1, 1] --> Compare (3, 2) --> Swap(3, 2)
 * [2, 3, 1, 1] --> Compare (3, 1) --> Swawp(3, 1)
 * [2, 1, 3, 1] --> Compare (3, 1) --> Swap(3, 1)
 * [2, 1, 1, 3] --> Compare (2, 1) --> Swap(2, 1)
 * [1, 2, 1, 3] --> Compare (2, 1) --> Swap(2, 1)
 * [1, 1, 2, 3] --> Compare(1, 1)
 * [1, 1, 2, 3] --> EXIT
 *
 * As one can see the stability is being preserved
 * For proving time complexity, worse case, is obviously reverse sorted array.
 * Takes   2 * (n - 1) + 2 * (n - 2) + ... + 2
 *       = 2 *  ( (n - 1) + (n - 2) + (n - 3) + (n - 4) + ... + 1 )
 *       = 2  * n * (n - 1) / 2
 *       = n * (n - 1)
 * Therefore Time Complexity: takes O(n^2)
 *           Space Complexity: O(1) or O(n), depends on whether you mutate the input array or not
 *           Stable: YES
 *
 *
 */
void bubble_sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        bool changed = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                changed = true;
            }
        }
        if (!changed) {
            break;
        }
    }
}

/**
 * MECHANISM:
 * Incrementally sorting!
 * It works like a shuffling a deck of cards in your hand.
 * First card is sorted.
 * Place the second card after comparing with the first
 * Place the third after comparing with the first and second.
 * It also builds a sorted array at the start but a progressive one.
 * In selection sort, the first iteration puts the smallest element in the array in the first place.
 * Where-as in selection sort, it only sorts the array upto which it has explored uptill the ith
 * iteration (which is i elements)
 *
 * Example: [3, 2, 1, 1]
 *          [3, 3, 1, 1]
 *          [2, 3, 1, 1]
 *          [2, 3, 3, 1]
 *          [2, 2, 3, 1]
 *          [1, 2, 3, 1]
 *          [1, 2, 3, 3]
 *          [1, 2, 2, 3]
 *          [1, 1, 2, 3]
 *  Conclusion: Time Complexity Algorithm:
 *              2 + 4 + ... + 2 * (n - 1)
 *              = n * (n - 1)
 *              TC: O(N^2)
 *              Space Complexity: O(1)
 *              Stability: YES
 * ADDITIONAL: Use it on big arrays that are almost sorted
 *
 *
 */
void insertion_sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int key = arr[i];
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/**
 * MECHANISM:
 * It's a divide and conquer mechanism. The subarrays are independent yet disjoint subproblems.
 * We solve each subproblem. And merge the two solutions back together.
 * TC: T(n) = 2*T(n/2) + O(n)
 *     a = 2
 *     b = 2
 *     log(a) / log(b) = 1
 *     k = 1
 *     Since they are equal, Ans is O(nlgn)
 * SC: O(n), not in place
 * TIPS: Piggy Bank Merge Sort (Counting Inversion)
 *       Naturally parallelizable
 *       Worse case TC O(nlgn)
 */
void merge_sort(vector<int>& arr, int left, int right, int& inversions) {
    int n = arr.size();
    if (right - left + 1 <= 1) {
        return;
    }
    int mid = left + (right - left) / 2;
    merge_sort(arr, left, mid, inversions);
    merge_sort(arr, mid + 1, right, inversions);
    merge(arr, left, right, inversions);
}

void merge(vector<int>& arr, int left, int right, int& inversions) {
    vector<int> merged(right - left + 1);
    int mid = left + (right - left) / 2;
    int start1 = left, start2 = mid + 1;
    int i = 0;
    while (start1 <= mid && start2 <= right) {
        if (arr[start1] > arr[start2]) {
            merged[i++] = arr[start2++];
            inversions += (mid - start1 + 1);  // WAS BUG
        } else {
            merged[i++] = arr[start1++];
        }
    }
    while (start1 <= mid) {
        merged[i++] = arr[start1++];
    }
    while (start2 <= right) {
        merged[i++] = arr[start2++];
    }
    for (int i = left; i <= right; i++) {
        arr[i] = merged[i - left];  // WAS BUG
    }
}

/**
 * TC: O(nlgn) But worse case: O(n^2)
 * SC: O(lg n) But worse case: O(n)
 * Stable: NO
 */

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quick_sort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

// QUICKSELECT: Gets the kth order stat lightning fast. Superposition of quick_sort and binary
// search of sense
// 0 based kth stats
void quickselect(vector<int>& arr, int low, int high, int k) {
    if (high > low) {
        int pi = partition(arr, low, high);
        if (pi == k) {
            // Yay!!!
            return;
        }
        if ((pi > k)) {
            // left half
            quickselect(arr, low, pi - 1, k);
        } else {
            quickselect(arr, pi + 1, high, k);
        }
    }
}

int main() {
    return 0;
}