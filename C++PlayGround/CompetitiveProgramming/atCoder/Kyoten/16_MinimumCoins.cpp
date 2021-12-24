#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  long long n, a, b, c;
  int cnt;
  cin >> n;
  cin >> a >> b >> c;
  cnt = n + 1;
  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < n + 1; j++) {
      long long tmp = n - i * a + j * b;
      if (tmp < 0 || tmp % c != 0)
	continue;
      int k = tmp / c;
      cnt = min(cnt, i + j  + k);
    }
  }
  cout << cnt << endl;
  return 0;

}
