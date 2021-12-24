#include <iostream>
#include <cmath>
using namespace std;

int main (){
  long long a, b, c;
  long long t;
  cin >> a >> b >> c;
  t = c;
  for (int i = 0; i < b - 1; i++) {
    t *= c;
  }
  cout << (a < t ? "Yes" : "No") << endl;
  return 0;
}
