#include <iostream>
using namespace std;

int countThreeSumZero(int arr[], int size)
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            for (int k = j + 1; k < size; k++)
            {
                if (arr[i] + arr[j] + arr[k] == 0)
                {
                    count++;
                }
            }
        }
    }

    return count;
}

int main()
{
    int arr[10] = {-3, 1, 2, -1, 4, -2, -4, 3, 0, 5}; // Example array

    int result = countThreeSumZero(arr, 10);
    cout << result;
    return 0;
}