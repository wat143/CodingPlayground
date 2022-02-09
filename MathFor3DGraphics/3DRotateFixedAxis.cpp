#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void rotate3d(vector<float> &vec, int deg, char axis) {
    float rad = deg * (M_PI / 180);
    float conv[4][4] = {0};
    vector<float> tmp(3, 0), vec4(4, 0);
    for (int i = 0; i < 3; i++)
        vec4[i] = vec[i];
    vec4[3] = 1;
    if (axis == 'x') {
        conv[0][0] = 1; conv[0][1] = 0; conv[0][2] = 0; conv[0][3] = 0;
        conv[1][0] = 0; conv[1][1] = cos(rad); conv[1][2] = -1 * sin(rad); conv[1][3] = 0;
        conv[2][0] = 0; conv[2][1] = sin(rad); conv[2][2] = cos(rad); conv[2][3] = 0;
        conv[3][0] = 0; conv[3][1] = 0; conv[3][2] = 0; conv[3][3] = 1;
    }
    else if (axis == 'y') {
        conv[0][0] = cos(rad); conv[0][1] = 0; conv[0][2] = -1 * sin(rad); conv[0][3] = 0;
        conv[1][0] = 0; conv[1][1] = 1; conv[1][2] = 0; conv[1][3] = 0;
        conv[2][0] = sin(rad); conv[2][1] = 0; conv[2][2] = cos(rad); conv[2][3] = 0;
        conv[3][0] = 0; conv[3][1] = 0; conv[3][2] = 0; conv[3][3] = 1;
    }
    else if (axis == 'z') {
        conv[0][0] = cos(rad); conv[0][1] = -1 * sin(rad); conv[0][2] = 0; conv[0][3] = 0;
        conv[1][0] = sin(rad); conv[1][1] = cos(rad); conv[1][2] = 0; conv[1][3] = 0;
        conv[2][0] = 0; conv[2][1] = 0; conv[2][2] = 1; conv[2][3] = 0;
        conv[3][0] = 0; conv[3][1] = 0; conv[3][2] = 0; conv[3][3] = 1;
    }
    else {
        cout << "Invalid axis" << endl;
    }
    
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
    float x, y, z, deg;
    char axis;
    cin >> x >> y >> z >> axis >> deg;
    vec[0] = x;
    vec[1] = y;
    vec[2] = z; 
    rotate3d(vec, deg, axis);
    cout << "(" << vec[0] << ", " << vec[1] << ", " << vec[2] << ")" << endl;
    return 0;
}