#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

#define INF 100000

int bellmanFord(vector<vector<int>> vec, int s, int g, vector<int>& cost) {
    queue<int> q;
    int cnt;
    bool updated = true;
    cost.resize(vec.size(), INF);
    cost[s] = 0;
    for (cnt = 0; cnt < vec.size() && updated; cnt++) {
        updated = false;
        vector<int> visited(vec.size(), 0);
        q.push(s);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (visited[cur])
                continue;
            for (int i = 0; i < vec.size(); i++) {
                if (vec[cur][i] != INF) {
                    int prev = cost[i];
                    cost[i] = min(cost[i], cost[cur] + vec[cur][i]);
                    if (prev != cost[i])
                        updated = true;
                    q.push(i);
                }
            }
            visited[cur] = 1;
        }
    }
    if (cnt == vec.size())
        return 0;
    else
        return 1;
}

int main() {
    vector<vector<int>> vec;
    int v, e, r;
    cin >> v >> e >> r;
    vec.resize(v);
    for (int i = 0; i < v; i++)
        vec[i].resize(v, INF);
    for (int i = 0; i < e; i++) {
        int s, d, c;
        cin >> s >> d >> c;
        vec[s][d] = c;
    }
    for (int i = 0; i < v; i++) {
        vector<int> cost;
        int ans = bellmanFord(vec, r, i, cost); 
        if (ans == 0) {
            cout << "NEGATIVE CYCLE" << endl;
            break;
        }
        else {
            if (cost[i] == INF)
                cout << "INF" << endl;
            else
                cout << cost[i] << endl;
        }
    }
    return 0;
}