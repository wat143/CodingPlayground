#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void rotate2d(vector<float> &vec, int deg) {
    vector<float> tmp(2, 0);
    float rad = deg * (M_PI / 180);
    float conv[2][2] ={{cos(rad), -1 * sin(rad)},
                       {sin(rad), cos(rad)}};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            tmp[i] += (conv[i][j] * vec[j]);
        }
    }
    vec = tmp;
}

int main() {
    vector<float> vec(2, 0);
    int x, y, degree;
    cin >> x >> y >> degree;
    vec[0] = x; vec[1] = y;
    rotate2d(vec, degree);
    cout << "(" << vec[0] << ", " << vec[1] << ")" << endl;
    return 0;
}