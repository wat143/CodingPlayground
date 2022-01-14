/*
a  b  c
10 40 70
20 50 80
30 60 90

  1   2   3
a 10  90  150 
b 40  120 180
c 70  120 210

*/

#include <iostream>
#include <vector>
using namespace std;

int DP[100000][3] = {0};

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (i == 0) {
            DP[i][0] = a;
            DP[i][1] = b;
            DP[i][2] = c;
        }
        else {
            int d1, d2;
            /* transit to a */
            d1 = DP[i - 1][1] + a;
            d2 = DP[i - 1][2] + a;
            DP[i][0] = max(d1, d2);
            /* transit to b */
            d1 = DP[i - 1][0] + b;
            d2 = DP[i - 1][2] + b;
            DP[i][1] = max(d1, d2);
            /* transit to c */
            d1 = DP[i - 1][0] + c;
            d2 = DP[i - 1][1] + c;
            DP[i][2] = max(d1, d2);
        }
    }
    ans = max(DP[n - 1][0], DP[n - 1][1]);
    ans = max(ans, DP[n - 1][2]);
    cout << ans << endl;
    return 0;
}