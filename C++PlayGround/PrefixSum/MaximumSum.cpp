#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    vector<long long> vec;
    long long m = 0;
    int n, k, z;
    cin >> n >> k;
    vec.push_back(0);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        vec.push_back(t + vec[i]);
    }
    cin >> z >> z;

    for (int i = k; i <= n; i++) {
        m = max(m, vec[i] - vec[i - k]);
    }
    cout << m << endl;
    return 0;
}