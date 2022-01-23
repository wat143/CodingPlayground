#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1000000000000000000
int main() {
    unsigned long long a, b, ans, g;
    cin >> a >> b;
    if (a < b)
        swap(a, b);
    g = __gcd(a, b);
    ans = b / g;
    if (ans > INF / a)
        cout << "Large" << endl;
    else
        cout << a * ans << endl;
    return 0;
}