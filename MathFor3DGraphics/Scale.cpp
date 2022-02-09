#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void scale(vector<float> &vec, float factor) {
    vector<float> tmp(4, 0), vec4(4);
    float conv[4][4] = {{factor, 0, 0, 0},
                        {0, factor, 0, 0},
                        {0, 0, factor, 0},
                        {0, 0, 0, 1}};
    for (int i = 0; i < 3; i++)
        vec4[i] = vec[i];
    vec4[3] = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            tmp[i] += conv[i][j] * vec4[j];
        }
    }
    for (int i = 0; i < 3; i++)
        vec[i] = tmp[i];
}

int main() {
    vector<float> vec(3);
    float x, y, z, factor;
    cin >> x >> y >> z >> factor;
    vec[0] = x;
    vec[1] = y;
    vec[2] = z;
    scale(vec, factor);
    cout << "(" << vec[0] << ", " << vec[1] << ", " << vec[2] << ")" << endl;
    return 0;
}