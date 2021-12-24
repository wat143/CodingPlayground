#include <iostream>
using namespace std;

#define ll long long

ll gcd(ll a, ll b) {
  ll rem = a % b;
  if (rem != 0)
    return gcd(b, rem);
  else
    return b;
}

int main() {
  ll x, y, z;
  ll div;
  cin >> x >> y >> z;
  div = gcd(gcd(x, y), z);
  cout << (x / div - 1) + (y / div - 1) + (z / div - 1) << endl;
  return 0;
}
