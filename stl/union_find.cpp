#include <iostream>
#include <vector>
using namespace std;

class UnionFind
{

private:
    int size;
    int components;
    vector<int> sizes;
    vector<int> relations;

public:
    UnionFind(int size)
    {
        this->size = size;
        this->components = size;
        this->relations.reserve(size);
        this->sizes.reserve(size);

        for (int i = 0; i < size; i++)
        {
            this->sizes[i] = 1;
            this->relations[i] = i;
        }
    }

    int find(int p)
    {
        int root = this->relations[p];

        while (root != this->relations[root])
        {
            root = this->relations[root];
        }

        // path compression
        while (p != root)
        {
            int next = this->relations[p];
            this->relations[p] = root;
            p = next;
        }

        return root;
    }

    int componentSize(int p)
    {
        return sizes[find(p)];
    }

    bool connected(int p, int q)
    {
        return find(p) == find(q);
    }

    void unify(int p, int q)
    {
        int root1 = find(p);
        int root2 = find(q);
        if (root1 == root2)
            return;

        int size1 = sizes[root1];
        int size2 = sizes[root2];

        if (size1 < size2)
            swap(root1, root2);
            
        relations[root2] = root1;
        sizes[root1] += sizes[root2];
        sizes[root2] = 0;
        components--;
    }
};