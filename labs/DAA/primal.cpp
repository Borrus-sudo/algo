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

    vector<bool> vis(n, false);
    int dist = 0;
    int start = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto source = pq.top();
        pq.pop();
        if (vis[source.second])
            continue;
        vis[source.second] = true;
        dist += source.first;
        for (auto edge : adjList[source.second]) {
            auto [cost, to] = edge;
            if (vis[to])
                continue;
            pq.push(edge);
        }
    }
    return 0;
}