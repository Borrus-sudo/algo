#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int elem;
    cin >> elem;

    for (int i = 0; i < 5; i++)
        if (arr[i] == elem)
        {
            cout << "Elem at: " << i << endl;
            return 0;
        }
    cout << "Elem not found";

    return 0;
}