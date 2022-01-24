#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int INF = 100000000;

// Debugging purpose
void printBit(int a) {
    int len = 16;
    int mask = 1 << (len - 1);
    for (int i = 0; i < len; i++) {
        if ((mask >> i) & a) cout << 1;
        else cout << 0;
    }
    cout << endl;
}

int main() {
    int v, e;
    cin >> v >> e;
    vector<vector<int> > vec(v, vector<int>(v));
    int dp[1 << v][v];
    for (int i = 0; i < (1 << v); i++) {
        for (int j = 0; j < v; j++) {
            if (i < v)
                vec[i][j] = INF;
            dp[i][j] = INF;
        }
    }   
    for (int i = 0; i < e; i++){
        int s, t, d;
        cin >> s >> t >> d;
        vec[s][t] = d;
    }
    dp[0][0] = 0;
    for (int i = 1; i < (1 << v); i++) {
        //printBit(i);
        for (int j = 0; j < v; j++) {
            int mask = 1 << j;
            if (i & mask) {
                //cout << j << endl;
                for (int k = 0; k < v; k++)
                    dp[i][j] = min(dp[i][j], dp[i - (1 << j)][k] + vec[k][j]);
            }
        }
    }
    if (dp[(1 << v) - 1][0] == INF) cout << -1 << endl;
    else cout << dp[(1 << v) - 1][0] << endl;
    return 0;
}