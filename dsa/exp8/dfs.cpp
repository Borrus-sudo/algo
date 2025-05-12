#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dfs(vector<vector<int>> adjMatrix, vector<bool> &visited, int root)
{
    if (visited[root])
        return;
    cout << root << endl;
    visited[root] = true;
    for (int neighbour : adjMatrix[root])
        dfs(adjMatrix, visited, neighbour);
}
int main()
{
    vector<vector<int>> adj = {
        {1, 2},
        {2},
        {0, 3},
        {3},
    };
    vector<bool> visited(adj.size(), false);
    dfs(adj, visited, 0);
    return 0;
}