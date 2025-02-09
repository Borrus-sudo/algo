/** FAIL */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int lines;
    cin >> lines;
    while (lines-- > 0)
    {
        int no, len;
        cin >> no;
        cin >> len;
        int **matrix = new int *[no];
        for (int row = 0; row < no; row++)
        {
            matrix[row] = new int[len];
            for (int col = 0; col < len; col++)
            {
                cin >> matrix[row][col];
            }
        }
        // each row in the matrix needs to be fixed of sorts by doing sorting
        sort(matrix, matrix + no, [no, len](int *arr1, int *arr2) -> bool
             {
            int payload = no * len;
            int first = 0;
            int second = 0;
            for (int i = 0; i < len; i++) {
               first += (payload * arr1[i]);
               second += (payload * arr2[i]);
               payload--;
            }
            return first > second ? true : false; });
        int totalScore = 0;
        int currScore = 0;
        for (int row = 0; row < no; row++)
        {
            for (int col = 0; col < len; col++)
            {
                currScore += matrix[row][col];
                totalScore += currScore;
            }
        }
        for (int i = 0; i < no; i++)
        {
            delete[] matrix[i]; // Delete each row
        }
        delete[] matrix;

        cout << totalScore << endl;
    }
    return 0;
}