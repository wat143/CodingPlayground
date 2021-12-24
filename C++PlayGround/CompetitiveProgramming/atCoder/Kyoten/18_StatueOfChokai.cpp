#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

int main() {
  int T, L, x, y, Q;
  vector<long double> E;
  cin >> T >> L >> x >> y >> Q;
  for (int i = 0; i < Q; i++) {
    int tmp;
    cin >> tmp;
    E.push_back(tmp);
  }

  // Calc points
  for (int i = 0; i < E.size(); i++) {
    long double vx, vy, vz;
    long double distA, distB;
    vx = 0;
    vy = -1 * (L / 2.0) * sin((E[i] / T) * (2 * M_PI));
    vz = -1 * (L / 2.0) * cos((E[i] / T) * (2 * M_PI)) + L / 2.0;
    distA = sqrt(pow(vx - x, 2) + pow(y - vy, 2) );
    distB = vz;
    cout << fixed << setprecision(7) << atan(distB / distA) * (180 / M_PI) << endl;
  }
  return 0;
}
