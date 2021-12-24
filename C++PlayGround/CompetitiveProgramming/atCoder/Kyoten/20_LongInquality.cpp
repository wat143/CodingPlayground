// This works only for not floating point value.
// In float case, some value may result in the wrong answer.
#include <iostream>
using namespace std;

void printBin(unsigned long long a) {
  int cnt = 0;
  for (unsigned long long int i = 1 << 31; i > 0; i = i >> 1) {
    if (cnt != 0 && cnt % 4 == 0)
      cout << " ";
    cout << (a & i ? 1 : 0);
    cnt++;
  }
  cout << endl;
}

int main() {
  unsigned long long a, b, c;
  unsigned long long int loga, logc;
  int cnt = 0;
  cin >> a >> b >> c;
  for (unsigned long long i = 1 << 31; i > 0; i = i >> 1) {
    cnt++;
    if (i & a)
      break;
  }
  loga = 32 - static_cast<unsigned long long>(cnt);
  cnt = 0;
  for (unsigned long long i = 1 << 31; i > 0; i = i >> 1) {
    cnt++;
    if (i & c)
      break;
  }
  logc = 32 - static_cast<unsigned long long>(cnt);
  if (loga < b * logc)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
