#include <algorithm>
#include <array>
using namespace std;

int main() {
    array<int, 5> arr{1, 2, 3, 4, 5};
    for (int i = 0; i < arr.size(); i++) {
        bool isSorted = true;
        for (int j = 0; j < arr.size() - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                isSorted = false;
            }

        if (isSorted)
            break;
    }

    return 0;
}