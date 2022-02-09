#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void rotate3d_arbit(vector<float> &vec3, vector<float> arb, float deg) {
    float rad = deg * (M_PI / 180);
    float c = cos(rad), s = sin(rad);
    vector<float> tmp(4, 0), vec4(4);
    float conv[4][4] = {
        {(arb[0] * arb[0]) - (arb[0] * arb[0]) * c + c, arb[0] * arb[1] - arb[0] * arb[1] * c - arb[2] * s, arb[0] * arb[2] - arb[0] * arb[2] * c + arb[1] * s, 0},
        {arb[0] * arb[1] - arb[0] * arb[1] * c + arb[2] * s, (arb[1] * arb[1]) - (arb[1] * arb[1]) * c + c, arb[1] * arb[2] - arb[1] * arb[2] * c - arb[0] * s, 0},
        {arb[0] * arb[2] - arb[0] + arb[2] * c - arb[1] * s, arb[1] * arb[2] - arb[1] * arb[2] * c + arb[0] * s, (arb[2] * arb[2]) - (arb[2] * arb[2]) * c + c, 0},
        {0, 0, 0, 1}
    };
    for (int i = 0; i < 3; i++)
        vec4[i] = vec3[i];
    vec4[3] = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            tmp[i] += conv[i][j] * vec4[j];
        }
    }
    for (int i = 0; i < 3; i++)
        vec3[i] = tmp[i];
}

int main() {
    vector<float> vec(3), axis(3);
    float x, y, z, deg;
    for (int i = 0; i < 3; i++) {
        float t;
        cin >> t;
        vec[i] = t;
    }
    for (int i = 0; i < 3; i++) {
        float t;
        cin >> t;
        axis[i] = t;
    }
    cin >> deg;
    rotate3d_arbit(vec, axis, deg);
    cout << "(" << vec[0] << ", " << vec[1] << ", " << vec[2] << ")" << endl;
    return 0;
}