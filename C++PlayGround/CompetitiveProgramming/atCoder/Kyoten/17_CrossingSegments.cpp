#include <iostream>
#include <vector>
using namespace std;

int main (){
  int n, m, cnt = 0;
  vector<pair<int, int>> v;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    v.push_back(make_pair(a, b));
  }

  for (int i = 0; i < m; i++) {
    int l1, r1;
    l1 = v[i].first;
    r1 = v[i].second;
    for (int j = i + 1; j < m; j++) {
      int l2, r2;
      l2 = v[j].first;
      r2 = v[j].second;
      if ((l1 < l2 && l2 < r1 &&r1 < r2) || (l2 < l1 && l1 < r2 &&r2 < r1))
	cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}
