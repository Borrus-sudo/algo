#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

using minheap = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;

// Connected graphs with postive edge weight, and no negative edge cycles
// TC: O(V*(V-1)) O((V + V) * V) = O(V^2)
void naive_djikstra(vector<vector<pair<int, int>>> adj_mat, int src, int dest) {
    int n = adj_mat.size();
    vector<int> dist(n, INT_MAX);
    vector<int> prev(n, -1);
    dist[src] = 0;
    // not covered
    // set of edges not covered!!!!
    set<int> s_compl;
    for (int i = 0; i < n; i++) {
        s_compl.insert(i);
    }
    while (!s_compl.empty()) {
        // find the vertex with the least dist
        int maxxy = INT_MAX;
        int curr = -1;
        for (int vertex : s_compl) {
            if (dist[vertex] < maxxy) {
                curr = vertex;
                maxxy = dist[vertex];
            }
        }
        s_compl.erase(s_compl.find(curr));
        if (curr == dest) {
            break;
        }

        // now go through all the vertices and decrease the dist
        // edge relaxation
        for (auto [endV, eCost] : adj_mat[curr]) {
            if (dist[endV] > dist[curr] + eCost) {
                dist[endV] = dist[curr] + eCost;
                prev[endV] = curr;
            }
        }
    }

    stack<int> path;
    int curr = dest;
    path.push(curr);
    while (prev[curr] != -1) {
        path.push(prev[curr]);
        curr = prev[curr];
    }
};

// The above djikstra can be optimized by having better data structures for s_compl.
// TC: V* (log V + logV * V) = E log V (duplicates can really make V swell!)
void lazy_djikstra(vector<vector<pair<int, int>>> adj_mat, int src, int dest) {
    int n = adj_mat.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> s_compl;
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    vector<int> prev(n, -1);
    s_compl.push({dist[src], src});

    while (!s_compl.empty()) {
        auto [dist_cost, startV] = s_compl.top();
        s_compl.pop();
        if (dist_cost != dist[startV])  // repeat
            continue;
        if (startV == dest)  // remove if you don't want to stop
            break;
        for (auto [endV, eCost] : adj_mat[startV]) {
            if (dist[endV] > dist[startV] + eCost) {  // edge relexation
                dist[endV] = dist[startV] + eCost;
                prev[endV] = startV;
                s_compl.push({dist[endV], endV});  // massive duplicate issue
            }
        }
    }

    stack<int> path;
    int curr = dest;
    path.push(curr);
    while (prev[curr] != -1) {
        path.push(prev[curr]);
        curr = prev[curr];
    }
}

// Eager_Djikstra solves the massive duplicate by coming with a heap variant data structure that
// supports decrease key ops
// Im not gonna write tis though. In paper, one can always assume an ADT.

// Bellman Ford
// TC: (V - 1) * E = O(EV)
// Handles negative edge weights and edge cycles too!
// You can stop performing when between successive iterations nothing changes
void bellman_ford(vector<vector<pair<int, int>>> adj_mat, int src, int dest) {
    int n = adj_mat.size();
    vector<int> dist(n, INT_MAX);
    vector<int> prev(n, -1);
    dist[src] = 0;
    for (int i = 1; i < n; i++) {  // |V| - times
        // go through all the edges
        for (int from = 0; from < n; from++) {
            auto edges = adj_mat[from];
            for (auto [to, e] : edges) {
                if (dist[from] != INT_MAX && dist[to] > dist[from] + e) {
                    dist[to] = dist[from] + e;
                    prev[to] = from;
                }
            }
        }
    }

    for (int from = 0; from < n; from++) {
        auto edges = adj_mat[from];
        for (auto [to, e] : edges) {
            if (dist[from] != INT_MAX && dist[to] > dist[from] + e) {
                dist[to] = INT_MIN;
                prev[to] = -1;
            }
        }
    }
}

// APSP
// Can be used for negative edge weights but not negative edge cycles!
// Negative edge cycles need correction you know
// TC: O(V^3)
void floyd_warshall(vector<vector<int>> adj_mat) {
    int n = adj_mat.size();
    vector<vector<int>> dist(n, vector<int>(n));
    vector<vector<int>> next(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = adj_mat[i][j];
            if (adj_mat[i][j] != INT_MAX)
                next[i][j] = j;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int from = 0; from < n; from++) {
            for (int to = 0; to < n; to++) {
                if (dist[from][k] == INT_MAX || dist[k][to] == INT_MAX)
                    continue;
                if (dist[from][k] + dist[k][to] < dist[from][to]) {
                    dist[from][to] = dist[from][k] + dist[k][to];
                    next[from][to] = next[from][k];  // go via the node k
                }
            }
        }
    }

    int from = 0;
    int to = n - 1;
    vector<int> path;
    // PATH exists
    if (dist[from][to] != INT_MAX)
        ;

    for (int at = from; at != to; at = next[at][to]) {
        path.push_back(at);
    }
    path.push_back(to);
}

int main() {
    return 0;
}