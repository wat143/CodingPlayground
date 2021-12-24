#include <iostream>
using namespace std;
#define DIV 1000000007

int main (){
  long long dp[100001][8] = {0};
  string s;
  int n;
  cin >> n >> s;
  dp[0][0] = 1;
  for (int i = 0; i < s.size(); i++) {
    for (int j = 0; j <= 7; j++) {
      dp[i + 1][j] += dp[i][j];
      if (s[i] == 'a' && j == 0) dp[i + 1][j + 1] += dp[i][j];
      if (s[i] == 't' && j == 1) dp[i + 1][j + 1] += dp[i][j];
      if (s[i] == 'c' && j == 2) dp[i + 1][j + 1] += dp[i][j];
      if (s[i] == 'o' && j == 3) dp[i + 1][j + 1] += dp[i][j];
      if (s[i] == 'd' && j == 4) dp[i + 1][j + 1] += dp[i][j];
      if (s[i] == 'e' && j == 5) dp[i + 1][j + 1] += dp[i][j];
      if (s[i] == 'r' && j == 6) dp[i + 1][j + 1] += dp[i][j];
    }
    for (int j = 0; j <= 7; j++) dp[i + 1][j] %= DIV;
  }

  cout << dp[s.size()][7] << endl;

  return 0;
}
