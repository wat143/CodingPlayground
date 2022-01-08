#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int arr[1000][1000];
int m = INT_MAX;
int restrict[1000][1000] = {0};

void _perm(int len, int n, int prev, vector<int> sum, vector<int> visited) {
    if (len == n) {
        int s = 0;
        for (int i = 0; i < sum.size(); i++) {
            s += sum[i];
        }
        m = min(m, s);
    }
    else {
        for (int i = 0; i < n; i++) {
            if (visited[i] != 1) {
                if (prev == -1) {
                    visited[i] = 1;
                    sum[i] = arr[len][i];
                    _perm(len + 1, n, i, sum, visited);
                    visited[i] = 0;
                }
                else if (restrict[prev][i] == 0) {
                    visited[i] = 1;
                    sum[i] = arr[len][i];
                    _perm(len + 1, n, i, sum, visited);
                    visited[i] = 0;
                }
            }
        }
    }
}

void perm(int n) {
    vector<int> sum(n, 0);
    vector<int> visited(n, 0);
    _perm(0, n, -1, sum, visited);
}

int main() {
    int N, M;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int tmp;
            cin >> tmp;
            arr[i][j] = tmp;
        }
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        restrict[t1 - 1][t2 - 1] = 1;
        restrict[t2 - 1][t1 - 1] = 1;
    }
    perm(N);
    if (m != INT_MAX) cout << m << endl;
    else cout << -1 << endl;
    return 0;
}