#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int M = 0;

void perm(int depth, int size, vector<int> yokan, int *arr, int left, int right) {
  if (depth == size) {
    int m = INT_MAX;
    for (int i = 1; i <= size + 1; i++) {
      int d = arr[i] - arr[i - 1];
      m = min(d, m);
    }
    M = max(M, m);
  }
  else {
    for (int i = left; i < right; i++) {
      arr[depth + 1] = yokan[i];
      perm(depth + 1, size, yokan, arr, i + 1, right);
    }
  }
}

int main() {
  vector<int> yokan;
  int n, l, k;
  cin >> n >> l >> k;
  yokan.push_back(0);
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    yokan.push_back(t);
  }
  yokan.push_back(l);
  int arr[k + 2];
  arr[0] = 0;
  arr[k + 1] = yokan[yokan.size() - 1];
  perm(0, k, yokan, arr, 1, n);
  cout << M << endl;
  return 0;
}
