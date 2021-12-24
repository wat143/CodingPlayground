#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_multimap<int, int> m;
unordered_multimap<int, int> Prev;

bool bfs(int s, int g, int N) {
  int visited[N] = {0};
  queue<int> q;
  q.push(s);
  cout << "Queue: " << s << "->" << g << endl;
  while (!q.empty()) {
    int c = q.front();
    q.pop();
    visited[c] = 1;
    auto range = m.equal_range(c);
    cout << c << ": ";
    for (auto itr = range.first; itr != range.second; itr++) {
      cout << itr->second << " ";
      if (itr->second == g) {
	Prev.insert(make_pair(c, g));
	cout << endl;
	return true;
      }
      else if (visited[itr->second] != 1) {
	q.push(itr->second);
	Prev.insert(make_pair(itr->first, itr->second));
      }
    }
    cout << endl;
  }
  return false;
}

int main() {
  int N, M;
  vector<pair<int, int>> v;
  long long cnt = 0;
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    m.insert(make_pair(x, y));
    v.push_back(make_pair(x, y));
  }
  for (auto vitr = v.begin(); vitr != v.end(); vitr++)
    bfs(vitr->first, vitr->second, N);
  for (auto vitr = v.begin(); vitr != v.end(); vitr++) {
    pair<int, int> p = *vitr;
    cout << "Search: " << p.first << ", " << p.second << endl;
    bool flg = false;
    auto range = Prev.equal_range(p.first);
    // Check previousely calculated
    for (auto itr = range.first; itr != range.second; itr++) {
      cout << "Prev: " << itr->first << "->" << itr->second << endl;
      if (itr->second == p.second) {
	flg = true;
	break;
      }
    }
    // If path exists, check back path
    if (flg) {
      auto range = Prev.equal_range(p.second);
      for (auto itr = range.first; itr != range.second; itr++) {
	cout << "Back: " << itr->first << "->" << itr->second << endl;
	if (itr->second == p.first) {
	  cnt++;
	  break;
	}
      }
    }
  }

  cout << cnt << endl;

  return 0;
}
