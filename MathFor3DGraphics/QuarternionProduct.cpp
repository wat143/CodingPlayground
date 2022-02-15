#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

float dotVec3(vector<float> v1, vector<float> v2) {
    float ret = 0;
    for (int i = 0; i < v1.size(); i++)
        ret += v1[i] * v2[i];
    return ret;
}

vector<float> productVec3(vector<float> v1, vector<float> v2) {
    vector<float> tmp(3, 0);
    if (v1.size() != v2.size())
        cout << "vector size are not same" << endl;
    else {
        tmp[0] = v1[1] * v2[2] - v1[2] * v2[1];
        tmp[1] = v1[2] * v2[0] - v1[0] * v2[2];
        tmp[2] = v1[0] * v2[1] - v1[1] * v2[0];
    }
    return tmp;
}

vector<float> productQuarternion(vector<float> q1, vector<float> q2) {
    // q1 = (w1, v1), q2 = (w2, q2)
    // q1 * q2 = (w1 * w2 - q1q2, q1w2 + q2w1 + q1 x q2)
    vector<float> v1, v2;
    vector<float> tmp(4, 0), prod(3, 0);
    for (int i = 1; i < 4; i++) {
        v1.push_back(q1[i]);
        v2.push_back(q2[i]);
    }
    tmp[0] = q1[0] * q2[0] - dotVec3(v1, v2);
    prod = productVec3(v1, v2);
    for (int i = 1; i < 4; i++) {
        tmp[i] = q1[0] * q2[i] + q2[0] * q1[i] + prod[i - 1];
    }
    return tmp;
}

int main() {
    vector<float> q1(4, 1.0), q2(4, 1.0);
    // Quartenion : q = (w, xi, yj, zk)
    // i * j * k = -1, i * j = -j * i = k, ...
    // q / |q^2| = ~q (Pure quarternion cas)
    // Create conjugate
    q1 = productQuarternion(q1, q2);
    for (int i = 0; i < 4; i++)
        cout << q1[i] << ", ";
    cout << endl;
    return 0;
}