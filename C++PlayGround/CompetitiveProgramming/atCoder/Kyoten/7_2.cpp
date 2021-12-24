#include <iostream>
#include <set>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
  multiset<long long> a;
  int n, q, min = INT_MAX, max = 0;
  cin >> n;
  // Input Ai and sort
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    a.insert(tmp);
  }
  // Input Bj
  cin >> q;
  for (int i = 0; i < q; i++) {
    int tmp;
    long long comp = INT_MAX;
    multiset<long long>::iterator left;
    cin >> tmp;
    left = a.lower_bound(tmp);
    if (left != a.end())
      comp = abs(*left - tmp);
    if (left != a.begin())
      comp = (comp < abs(*(prev(left)) - tmp)) ? comp : abs(*(prev(left)) - tmp);
    cout << comp << endl;
  }
  return 0;
}
