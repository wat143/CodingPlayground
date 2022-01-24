#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n, k, idx = 0;
    vector<int> a;
    cin >> n >> k;
    int dp[k + 1];
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a.push_back(t);
    }
    for (int i = 0; i <= k; i++) {
        int cnt = 0;
        int l = 0;
        for (int j = 0; j < n; j++) {
            if (k - a[i] < 0)
                break;
            cnt++;
            if (!dp[k - a[i]])
                l++;
        }
        if (cnt == 0) dp[k] = 0;
        else if (l > 0) dp[k] = 1;
        else dp[k] = 0;
    }
    if (dp[k]) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}