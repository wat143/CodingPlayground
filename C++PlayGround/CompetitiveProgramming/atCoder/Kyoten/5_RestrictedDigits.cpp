#include <iostream>
#include <vector>

using namespace std;

#define DIV 1000000007
#define ll long long

int main() {
  ll n;
  int k, b;
  vector<int> c;

  cin >> n >> b >> k;
  for (int i = 0; i < k; i++) {
    int t;
    cin >> t;
    c.push_back(t);
  }

  // Solve with DP
  int dp[n][30] = {0};
  // for 1st dicimal place
  for (int i = 0; i < k; i++)
    dp[0][c[i] % b]++;
  // for remining parts
  for (ll i = 0; i < n - 1; i++) {
    for (int j = 0; j < b; j++) {
      for (int l = 0; l < k; l++) {
	int next = (j * 10 + c[l]) % b;
	dp[i + 1][next] += dp[i][j];
	dp[i + 1][next] %= DIV;
      }
    }
  }

  cout << dp[n - 1][0] << endl;
  return 0;
}
