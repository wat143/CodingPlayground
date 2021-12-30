#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long sum = 0;
    int n, k;
    bool flg = false;
    vector<int> a, b;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a.push_back(t);
    }
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        b.push_back(t);
    }
    for (int i = 0; i < n; i++) {
        sum += abs(a[i] - b[i]);
    }
    if (sum > k)
        flg = false;
    else if ((k - sum) % 2 == 0)
        flg = true;
    else
        flg = false;
    cout << (flg ? "Yes" : "No") << endl;
    return 0;
}
