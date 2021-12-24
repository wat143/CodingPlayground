#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> vert, hori, A[1 << 12];
  int h, w, sum_h = 0;
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    sum_h = 0;
    for (int j = 0; j < w; j++) {
      int val;
      cin >> val;
      A[i].push_back(val);
      sum_h += val;
      if (i == 0)
	vert.push_back(val);
      else
	vert[j] += val;
    }
    hori.push_back(sum_h);
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cout << hori[i] + vert[j] - A[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
