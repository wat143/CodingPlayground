#include<iostream>
#include<ctime>
using namespace std;

long long FibonacciRecur(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return FibonacciRecur(n - 1) + FibonacciRecur(n - 2);
}

int main() {
    int n;
    time_t s, e;
    cin >> n;
    // Fibonacci memorization
    long long memo[n];
    time(&s);
    for (int i = 0; i < n; i++) {
        if (i == 0 || i == 1) {
            memo[i] = 1;
        }
        else {
            memo[i] = memo[i - 1] + memo[i - 2];
        }
    }
    e = time(&e);
    cout << memo[n - 1] << endl;
    cout << "Memorization solution: " << e - s << endl;
    // Fibonacci recursive
    time(&s);
    long long ret = FibonacciRecur(n - 1);
    time(&e);
    cout << ret << endl;
    cout << "Recursive solution: " << e - s << endl;
    return 0;
}