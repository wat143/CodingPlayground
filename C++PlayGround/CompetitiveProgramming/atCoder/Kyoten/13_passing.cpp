#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dijkstra(vector<vector<int>> vec, int start, int goal) {
  vector<int> cost(vec.size() + 1, 1000000000);
  vector<int> visited(vec.size() + 1, 0);
  queue<int> que;
  cost[start] = 0;

  que.push(start);
  while (!que.empty()) {
    int idx = que.front();
    visited[idx] = 1;
    que.pop();
    for (int j = 1; j < vec.size(); j++) {
      if (vec[idx][j] > 0) {
	cost[j] = min(cost[j], cost[idx] + vec[idx][j]);
	if (visited[j] == 0)
	  que.push(j);
      }
    }
  }
  return cost[goal];
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> vec(n + 1, vector<int>(n + 1, 0));

  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    vec[a][b] = c;
    vec[b][a] = c;
  }

  for (int i = 1; i <= n; i++)
    cout << dijkstra(vec, 1, i) + dijkstra(vec, i, n) << endl;

  return 0;
}
