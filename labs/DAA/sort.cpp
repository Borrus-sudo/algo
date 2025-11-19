#include <vector>
using namespace std;

void insertion(vector<int>& A) {
    int n = A.size();
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int key = A[i];
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

void bubble(vector<int>& A) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1])
                swap(A[j], A[j + 1]);
        }
    }
}

int partition(vector<int>& A, int low, int high) {
    int key = A[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (A[j] < key) {
            i++;
            swap(A[i], A[j]);
        }
    }
    i++;
    swap(A[i], A[high]);
    return i;
}

void quicksort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int split = partition(arr, low, high);
        quicksort(arr, low, split - 1);
        quicksort(arr, split + 1, high);
    }
}

void mergesort(vector<int>& arr, int low, int high) {
    if (high - low <= 1)
        return;
    int mid = low + (high - low) / 2;
    mergesort(arr, low, mid);
    mergesort(arr, mid, high);
    merge(arr, low, high);
}

void merge(vector<int>& arr, int low, int high) {
    int mid = low + (high - low) / 2;
    int i = low;
    int j = mid;
    vector<int> merged;
    while (i < mid && j < high) {
        if (arr[i] <= arr[j]) {
            merged.push_back(arr[i]);
            i++;
        } else if (arr[i] > arr[j]) {
            merged.push_back(arr[j]);
            j++;
        }
    }
    while (i < mid) {
        merged.push_back(arr[i++]);
    }
    while (j < high) {
        merged.push_back(arr[j++]);
    }
    int idx = 0;
    for (int elem : merged)
        arr[low + idx++] = elem;
}
