#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n;
    map<string, int> m;
    vector<int> ans;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        if (m.count(tmp) == 0) {
            m[tmp] = 1;
            ans.push_back(i + 1);
        }
        else
            continue;
    }
    for (int i : ans)
        cout << i << endl;
    return 0;
}
