#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binSearch(vector<int> a, int target) {
  int left = -1, right = a.size();
  while (right - left > 1) {
    int mid = left + (right - left) / 2;
    if (a[mid] >= target)
      right = mid;
    else
      left = mid;
  }
  return right;
}

int main() {
  vector<int> a;
  int n, q;

  cin >> n;
  // Input Ai and sort
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    a.push_back(tmp);
  }
  sort(a.begin(), a.end());

  // Input Bj
  cin >> q;
  for (int i = 0; i < q; i++) {
    int tmp, left, right;
    long long comp = 0, lc, rc;
    cin >> tmp;
    right = binSearch(a, tmp);
    left = right - 1;
    if (left >= 0) {
      lc = abs(a[left] - tmp);
      rc = abs(a[right] - tmp);
      comp = (lc < rc) ? lc : rc;
    }
    else
      comp = abs(a[right] - tmp);
    cout << comp << endl;
  }
  return 0;
}
