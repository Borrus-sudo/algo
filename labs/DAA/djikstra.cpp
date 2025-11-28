#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/**
 * Djikstra is a single source shortest path algorithm.
 * It takes a connected simple graph with positive edges and works its magic.
 * If the graph has multiple edges, pick the smallest one and if it has loops, remove them.
 * the implementation below _should_ be resistant to both. But again I ain't doing a correctness
 * proof
 * TC is ElogV
 * Here is the proof the algorithm using Mathematical Induction:
 *
 *
 * Consider a function L to be a labelling function which gives the shortest distance to a given
 * vertex starting from the source vertex using all the vertices in the S itself.
 * Consider set S to be a set of vertices that whose labelling L is the shortest distance from the
 * source vertex S to that vertex.
 *
 * For all v in V
 *     if v == src
 *          L(v) = 0
 *      else
 *          L(v) = INF
 *
 * I give up nvm
 *
 *
 *
 */

int main() {
    int n = 10;
    using edge = pair<int, int>;  // <cost, index>
    using minheap = priority_queue<edge, vector<edge>, greater<edge>>;

    vector<vector<edge>> adj(n);  // every idx is node id. Every node ID
    vector<int> dist(n, INT_MAX);
    vector<int> prev(n, -1);
    minheap s;

    int src = 0;

    for (int i = 1; i < n; i++) {
        if (i == src)
            dist[i] = 0;
        else
            dist[i] = INT_MAX;
        prev[i] = -1;
        s.push({dist[i], i});
    }

    int target = n - 1;

    while (!s.empty()) {
        // pick the node with the least dist[u]
        auto [cost, u] = s.top();
        s.pop();
        if (u ==
            target) {  // Remove this condition if you want to find shortest paths till all nodes
            cout << cost << endl;
            break;
        }
        if (cost != dist[u]) {  // duplicate
            continue;
        }
        for (auto [edgeCost, v] : adj[u]) {
            if (dist[u] + edgeCost < dist[v]) {
                dist[v] = dist[u] + edgeCost;
                prev[v] = u;
                s.push({dist[v], v});  // decrease priority helps with the duplicates
            }
        }
    }

    return 0;
}