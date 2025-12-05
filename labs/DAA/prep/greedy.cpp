#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Primal Algorithm
void primalMST(vector<vector<int>> adj_mat) {
    using minheap = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
    minheap pq;
    int totalWeight = 0;
    int n = adj_mat.size();
    vector<bool> visited(n, false);
    pq.push({0, 0});
    while (!pq.empty()) {
        auto [edge, from] = pq.top();
        pq.pop();
        if (visited[from])
            continue;
        visited[from] = true;
        totalWeight += edge;
        for (int to = 0; to < n; to++) {
            if (visited[to])
                continue;
            pq.push({adj_mat[from][to], to});
        }
    }
}

class UnionFind {
    vector<int> relations;

   public:
    int components;

    UnionFind(int n) {
        this->components = n;
        this->relations = vector<int>(n);
        for (int i = 0; i < n; i++) {
            this->relations[i] = i;
        }
    }

    void compress(int a) {
        int head = a;
        while (this->relations[head] != head) {
            head = this->relations[head];
        }
        int node = a;
        while (this->relations[node] != node) {
            int next = this->relations[node];
            this->relations[node] = head;
            node = next;
        }
    }
    bool connected(int a, int b) {
        this->compress(a);
        this->compress(b);
        return this->relations[a] == this->relations[b];
    }
    void unionify(int a, int b) {
        this->components--;
        this->relations[b] = a;
    }
};

void kruskalMST(vector<vector<int>> adj_mat) {
    int totalWeight = 0;
    int n = adj_mat.size();
    using edges = pair<int, pair<int, int>>;
    vector<edges> Edges;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                Edges.push_back({adj_mat[i][j], {i, j}});
            }
        }
    }
    sort(Edges.begin(), Edges.end());
    int coveredVertices = 0;
    int totalWeight = 0;
    UnionFind* vertices = new UnionFind(n);
    for (auto [cost, currEdge] : Edges) {
        auto [from, to] = currEdge;
        if (vertices->connected(from, to)) {
            continue;
        }
        totalWeight += cost;
        vertices->unionify(from, to);
        if (vertices->components == 1) {
            break;
        }
    }
}

int main() {
    return 0;
}