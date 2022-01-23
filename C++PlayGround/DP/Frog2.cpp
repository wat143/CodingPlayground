#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define INF INT_MAX

int main() {
    int N, K;
    vector<int> h, dp;
    cin >> N >> K;
    for (int i = 0; i < N; i++){
        int t;
        cin >> t;
        h.push_back(t);
    }
    dp.resize(N, INF);
    dp[0] = 0;
    for (int i = 0; i < N - 1; i++) {
        int diff;
        for (int j = 1; j <= K; j++) {
            if (i + j < N) {
                diff = abs(h[i] - h[i + j]);
                dp[i + j] = min(dp[i + j], dp[i] + diff);
            }
        }
    }
    cout << dp[N - 1] << endl;
    return 0;
}