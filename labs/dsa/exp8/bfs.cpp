#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>> adjMatrix)
{
    vector<bool> visited(adjMatrix.size(), false);
    queue<int> upNext;
    upNext.push(0);
    visited[0] = true;

    while (!upNext.empty())
    {
        int currNode = upNext.front();
        upNext.pop();

        cout << currNode << endl;

        for (int neighbour : adjMatrix[currNode])
        {
            if (!visited[neighbour])
            {
                upNext.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }
}

int main()
{
    vector<vector<int>> adj = {
        {1, 2},
        {2},
        {0, 3},
        {3},
    };

    bfs(adj);
    return 0;
}