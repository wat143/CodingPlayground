#include<iostream>
#include<vector>
using namespace std;

void translate(vector<float> &vec, vector<float> trans) {
    vector<float> tmp(4, 0), vec4(4);
    float conv[4][4] ={{1, 0, 0, trans[0]},
                       {0, 1, 0, trans[1]},
                       {0, 0, 1, trans[2]},
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
    vector<float> vec3(3), trans(3);
    for (int i = 0; i < 3; i++) {
        float t;
        cin >> t;
        vec3[i] = t;
    }
    for (int i = 0; i < 3; i++) {
        float t;
        cin >> t;
        trans[i] = t;
    }
    translate(vec3, trans);
    cout << "(" << vec3[0] << ", " << vec3[1] << ", " << vec3[2] << ")" << endl;
    return 0;
}