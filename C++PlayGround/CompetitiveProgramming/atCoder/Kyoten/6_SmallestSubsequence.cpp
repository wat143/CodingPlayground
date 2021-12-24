#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

int main() {
  int n, k;
  vector<int> rank;
  string s, out;
  cin >> n >> k >> s;
  for (int i = 0; i < s.length(); i++) {
    int r = s[i] - 'a';
    rank.push_back(r);
  }

  int index = 0;
  for (int i = 0; i < k; i++) {
    int min = INT_MAX;
    int sub = (k - i > 0) ? k - i : 0;
    for (int j = index; j <= s.size() - sub; j++) {
      if (min > rank[j]) {
	min = rank[j];
	index = j;
      }
    }
    out.push_back(s[index]);
    index++;
  }

  cout << out << endl;
  return 0;
}
