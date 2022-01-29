#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int main() {
    int n, dp[100001];
    vector<int> v;
    cin >> n;
    // Create input pattern
    for (int i = 0, idx = 0, cnt = 1; i < n; i++, idx++) {
        if (idx == 0) {
            i = 1;
            v.push_back(i);
        }
        else if (idx % 2 == 0) {
            i = pow(6, cnt);
            v.push_back(i);
        }
        else {
            i = pow(9, cnt++);
            v.push_back(i);
        }
    }
    v.erase(prev(v.end()));
    // Init DP table
    for (int i = 0; i <= n; i++)
        dp[i] = 100000;
    dp[0] = 0;
    // Calculation (Receive DP)
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < v.size(); j++) {
            if (i - v[j] >= 0)
                dp[i] = min(dp[i], dp[i - v[j]] + 1);
        }
    }
    cout << dp[n] << endl;
    return 0;
}