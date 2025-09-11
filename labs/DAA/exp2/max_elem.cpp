#include <array>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

int main()
{

    array<int, 5> arr{1, 2, 3, 4, 5};

    int max_elem = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
    {

        max_elem = max(arr[i], max_elem);
    }

    cout << max_elem << endl;

    return 0;
}