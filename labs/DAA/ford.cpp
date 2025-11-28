#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/**
 * Bellman-Ford is SSSP algorithm that can handle negative weights and edge cycles
 * Refer Williamfiset video and check the comments, pretty informative
 * TC: O(EV), so pretty fucked up
 */

int main() {
    int n = 10;
    using edge = pair<int, int>;  // <cost, index>
    vector<long long> dist(n, INT_MAX);
    int src = 0;
    int vertices = n;
    vector<vector<edge>> adj(n, vector<edge>());

    for (int _ = 1; _ < vertices; _++) {
        for (int i = 0; i < vertices; i++) {
            int from = i;
            for (auto [cost, to] : adj[i]) {
                // edge relaxation
                if (dist[from] + cost < dist[to]) {
                    dist[to] = dist[from] + cost;
                }
            }
        }
    }

    for (int _ = 1; _ < vertices; _++) {
        for (int i = 0; i < vertices; i++) {
            int from = i;
            for (auto [cost, to] : adj[i]) {
                // edge relaxation
                if (dist[from] + cost < dist[to]) {
                    dist[from] = INT_MIN;
                }
            }
        }
    }

    return 0;
}