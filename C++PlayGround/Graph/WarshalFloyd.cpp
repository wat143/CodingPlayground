#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

#define INF 100000

void WarshalFloyd(vector<vector<int>> vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec.size(); j++) {
            for (int k = 0; k < vec.size(); k++) {
                vec[i][k] = min(vec[i][k], vec[i][j] + vec[j][k]);
            }
        }
    }
}

int main() {
    vector<vector<int>> vec, cost;
    int v, e;
    cin >> v >> e;
    vec.resize(v);
    for (int i = 0; i < v; i++) {
        vec[i].resize(v, INF);
        vec[i][i] = 0;
    }
    for (int i = 0; i < e; i++) {
        int s, d, c;
        cin >> s >> d >> c;
        vec[s][d] = c;
    }
    WarshalFloyd(vec);
    for (int i = 0; i < vec.size(); i++) {
        for (int j  = 0; j < vec.size(); j++) {
            if (i != j && vec[i][j] != INF)
                cout << i << " to " << j << ": " << vec[i][j] << endl;
        }
    }
    return 0;
}