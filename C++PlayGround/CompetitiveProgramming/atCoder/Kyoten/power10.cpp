#include <iostream>

using namespace std;

#define LL long long

long long modpow(long long a, long long b, long long m) {
	long long p = 1, q = a;
	for (int i = 0; i < 63; i++) {
		if ((b & (1LL << i)) != 0) {
			p *= q;
			p %= m;
		}
		q *= q;
		q %= m;
	}
	return p;
}

int main() {
  for (int i = 0; i < 31; i++)
    cout << modpow(10LL, (1LL << i), 7) << endl;
  return 0;
}
