#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  long long sum = 0;
  vector<int> a, b;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    a.push_back(t);
  }
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    b.push_back(t);
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  for (int i = 0; i < n; i++)
    sum += abs(a[i] - b[i]);
  cout << sum << endl;
  return 0;
}
