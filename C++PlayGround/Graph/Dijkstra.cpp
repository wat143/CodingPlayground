#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

#define INF 100000

int dijkstra(vector<vector<int>> vec, int s, int g) {
    vector<int> visited(vec.size(), 0), cost(vec.size(), INF);
    queue<int> q;
    bool updated;
    q.push(s);
    cost[s] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (visited[cur])
            continue;
        for (int i = 0; i < vec.size(); i++) {
            if (vec[cur][i] > 0 && cost[i] > cost[cur] + vec[cur][i]) {
                cost[i] = cost[cur] + vec[cur][i];
                updated = true;
            }
            q.push(i);
        }
        visited[cur] = 1;
    }

    return cost[g];
}

int main() {
    vector<vector<int>> vec;
    int v, e, r;
    cin >> v >> e >> r;
    vec.resize(v);
    for (int i = 0; i < v; i++)
        vec[i].resize(v, -1);
    for (int i = 0; i < e; i++) {
        int s, d, c;
        cin >> s >> d >> c;
        vec[s][d] = c;
    }
    for (int i = 0; i < v; i++) {
        int ans = dijkstra(vec, r, i); 
        if (ans == INF) cout << "INF" << endl;
        else cout << ans << endl;
    }
    return 0;
}