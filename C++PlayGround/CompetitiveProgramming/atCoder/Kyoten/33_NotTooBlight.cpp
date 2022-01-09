#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double h, w;
    cin >> h >> w;
    if (h == 1 || w == 1)
        cout << h * w << endl;
    else
        cout << ceil(h / 2) * ceil(w / 2) << endl;
    return 0;
}