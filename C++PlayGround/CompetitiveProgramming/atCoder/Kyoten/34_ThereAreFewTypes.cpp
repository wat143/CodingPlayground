/*
Memo
k = 2
1 1 2 4 2

1 1 2 2 3 3
1 1 2 2 3
    1 1 2 2  
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int n, k, ans = 0;
    int head = 0, tail = 0, type = 0;
    map<int, int> mp;
    vector<int> vec;
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        int t;
        cin >> t;
        vec.push_back(t);
    }
    while (tail < n && head < n) {
        if (type <= k) {
            if (mp.count(vec[tail]) == 0 || mp[vec[tail]] == 0) {
                mp[vec[tail]] = 1;
                type++;
                if (type > k)
                    continue;
            }
            else {
                mp[vec[tail]]++;
            }
            ans = max(ans, tail - head + 1);
            tail++;
        }
        else {
            mp[vec[head]]--;
            if (mp[vec[head]] == 0)
                type--;
            head++;
            if (type == k) {
                ans = max(ans, tail - head + 1);
                tail++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
