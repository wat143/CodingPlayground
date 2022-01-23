/*
v w
1 2
2 5
4 1

   0  1  2  3  4  5  6  7 === v
0  0  2  2  2  2  2  2  2
1  0  0  0  2  2  2  2  2
2  0  0  0  0  0  0  
*/

#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

long long kp[100][100001];

int main() {
    int N, W;
    cin >> N >> W;
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= 100000; j++)
            kp[i][j] = INT_MAX;

    for (int i = 0; i < N; i++) {
        int w, v;
        cin >> w >> v;
        if (i == 0) {
             kp[i][v] = w;
        }
        else {
            for (int j = 1; j <= 100000; j++) {
                if (j < v)
                    kp[i][j] = kp[i - 1][j];
                else
                    kp[i][j] = min(kp[i - 1][j - v] + w, kp[i - 1][j]);
            }
            cout << endl;
        }
    }
    int ans = 100000;
    while (kp[N - 1][ans] > W) ans--;
    cout << ans << endl;
    return 0;
}