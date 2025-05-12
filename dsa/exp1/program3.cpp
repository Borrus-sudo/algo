#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int newArr[6];
    int elem, pos;
    cin >> elem >> pos;

    for (int i = 0, j = 0; i < 5; i++, j++)
    {
        if (i == pos)
            newArr[j++] = elem;
        newArr[j] = arr[i];
    }

    for (int i = 0; i < 6; i++)
    {
        cout << "Elem at " << i << ": " << newArr[i] << endl;
    }

    return 0;
}