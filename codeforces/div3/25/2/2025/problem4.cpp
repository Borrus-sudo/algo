#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    int lines;
    cin >> lines;
    while (lines-- > 0)
    {
        int n, elem;
        cin >> n;
        int copy = n;
        vector<int> problem;
        while (--copy >= 0)
        {
            cin >> elem;
            problem.push_back(elem);
        }
        // now we have the problem
        int credit = 0;
        int global_cred = 0, from = 0, to = 0;
        int point_of_return = -1;
        int i = 0;
        int j = i + 1;
        while (j < problem.size() || point_of_return != -1)
        {
            if (j >= problem.size())
            {
                i = point_of_return;
                j = i + 1;
                point_of_return = -1;
                credit = 0;
                continue;
            }
            int left = problem[i];
            int right = problem[j];
            if (left > right)
            {
                credit++;
                j++;
                if (credit > global_cred)
                {
                    global_cred = credit;
                    from = i;
                    to = j - 1;
                }
            }
            else if (right > left)
            {
                // I met a bigger elem
                if ((credit - 1) > 0)
                {
                    credit--;
                    if (point_of_return == -1)
                    {
                        point_of_return = j;
                    }
                    j++;

                    continue;
                }
                credit = 0;
                i = point_of_return != -1 ? point_of_return : j;
                j = i + 1;
                point_of_return = -1;
            }
            else
            {
                j++;
            }
        }
        cout << (from + 1) << " " << (to + 1) << endl;
    }
    return 0;
}