/*
N = 5
h = 1, 3, 2, 9, 4

1st: 0 2 1 INF INF
2nd: 0 2 1 8   INF
3rd  0 2 1 8   4
4th  0 2 1 8   4
ans = 4
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define INF INT_MAX

int main()  {
    int N;
    vector<int> h, dp;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int t;
        cin >> t;
        h.push_back(t);
    }
    dp.resize(N, INF);
    dp[0] = 0;
    for (int i = 0; i < N - 1; i++) {
        int h1, h2;
        h1 = abs(h[i + 1] - h[i]);
        if (i + 2 < N)
            h2 = abs(h[i + 2] - h[i]);
        dp[i + 1] = min(dp[i + 1], dp[i] + h1);
        dp[i + 2] = min(dp[i + 2], dp[i] + h2);
    }
    cout << dp[N - 1] << endl;
    return 0;
}