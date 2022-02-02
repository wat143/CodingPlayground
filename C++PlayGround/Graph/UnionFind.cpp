#include<iostream>
#include<vector>
using namespace std;

class UnionFind {
private:
    vector<int> tree;
    vector<int> rank;
public:
    UnionFind(int n): tree(vector<int>(n)), rank(vector<int>(n, 0)) {
        for (int i = 0; i < n; i++) tree[i] = i;
    };
    int root(int x) {
        if (tree[x] == x) return x;
        else return tree[x] = root(x);
    }
    bool sameRoot(int x, int y) {
        return root(x) == root(y);
    }
    void unite(int x, int y) {
        int root_x = root(x);
        int root_y = root(y);
        if (rank[root_y] > rank[root_x])
            tree[root_x] = root_y;
        else {
            tree[root_y] = root_x;
            if (rank[root_x] == rank[root_y])
                rank[root_x]++;
        }
    }
};