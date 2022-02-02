/*
Memo
l = 3, r = 7
3 4 5 6 7 8
1 0 1 0 1 0

0 1 1 1 1 0
*/

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

bool isPrime(int t) {
    bool ret = true;
    for (int i = 2; i * i <= t; i++) {
        if (t % i == 0) {
            ret = false;
            break;
        }
    }
    return ret;
}

int main() {
    int q, l, r;
    int prime[100002];
    cin >> q;
    prime[0] = 0;
    for (int i = 1; i <= 100000; i++) {
        if (isPrime(i) && isPrime((i + 1) / 2))
            prime[i] += prime[i - 1] + 1;
        else
            prime[i] = prime[i - 1];
    }
    for (int i = 0; i < q; i++) {
        cin >> l >> r;
        cout << prime[r] - prime[l - 1] << endl;
    }
    return 0;
}