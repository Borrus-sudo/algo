#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/**
 * Floyd-Warshall is an all source shortest path algorithm.
 * It takes any graph and can work its magic even with negative edges.
 * If the graph has negative cycles, there are ways exist to modify and do it. Am gonna leave it
 * blank for rn. Also negative cycles is bad for the shortest path as you can keep traversing it
 * again and again The algorithm for transitive closures is very similar to this one, just a slight
 * modification
 *
 */

int main() {
    int n = 10;
    using edge = pair<int, int>;  // <cost, index>
    using minheap = priority_queue<edge, vector<edge>, greater<edge>>;

    vector<vector<edge>> adj(n + 1);  // every idx is node id. Every node ID
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));

    // initialize the dp according to the adj matrix

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dp[i][k] != INT_MAX && dp[k][j] != INT_MAX) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
    }

    return 0;
}