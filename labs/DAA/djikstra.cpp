#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    using edge = pair<int, int>;  // <cost, index>
    int n = 10;
    vector<vector<edge>> adjList(n);  // every idx is node id. Every node ID

    vector<int> dist;
    vector<bool> vis(n, false);
    vector<int> dist(n, INT_MAX);
    vector<int> prev(n, -1);

    int start = 0;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto source = pq.top();
        pq.pop();
        if (vis[source.second])
            continue;
        vis[source.second] = true;
        for (auto edge : adjList[source.second]) {
            auto [cost, to] = edge;
            if (vis[to])
                continue;
            if (cost + dist[source.second] < dist[to]) {
                prev[to] = source.second;
                dist[to] = cost + dist[source.second];
                pq.push(edge);
            }
        }
    }
    return 0;
}