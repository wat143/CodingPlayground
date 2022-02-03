#include<iostream>
#include<vector>
#include<algorithm>
#include"UnionFind.h"
using namespace std;

struct Edge {
    int u;
    int v;
    int c;
};

int Kruskal(vector<struct Edge> edge, int v) {
    int sum = 0, cnt = 0;
    UnionFind uf(edge.size());
    // Sort with cost ascending order
    sort(edge.begin(), edge.end(),
        [](const Edge &a, const Edge &b) { return a.c < b.c ? 1 : 0; });
    // Append edge to union find tree which is not connected yet
    for (int i = 0; i < edge.size(); i++) {
        Edge tmp = edge[i];
        if (!uf.sameRoot(tmp.u, tmp.v)) {
            uf.unite(tmp.u, tmp.v);
            sum += tmp.c;
        }
    }
    return sum;
}

int main() {
    vector<Edge> edge;
    int v, e;
    cin >> v >> e;
    edge.resize(e);
    for (int i = 0; i < e; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        edge[i].u = s;
        edge[i].v = t;
        edge[i].c = w;
    }
    cout << Kruskal(edge, v) << endl;
    return 0;
}