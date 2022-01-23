/*
weight limit = 8
w c
6 5
5 6
6 4
6 6
3 5
7 2

  0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15
0 0  0  0  0  0  0  5  5  5  5  5  5  5  5  5  5
1 0  0  0  0  0  6  11 11 11 11 11 11 11 11 11 11 11 11
2 0  0  0  0  0  6      
3
4
5

*/

#include <iostream>
using namespace std;

long long kp[100][100000] = {0};

int main() {
    int N, W;
    cin >> N >> W;
    for (int i = 0; i < N; i++) {
        int w, v;
        cin >> w >> v;
        if (i == 0) {
            for (int j = w; j <= W; j++) {
                kp[i][j] = v;
            }
        }
        else {
            for (int j = 1; j <= W; j++) {
                if (j < w)
                    kp[i][j] = kp[i - 1][j];
                else
                    kp[i][j] = max(kp[i - 1][j - w] + v, kp[i - 1][j]);
            }
        }
    }
    cout << kp[N - 1][W] << endl;
    return 0;
}