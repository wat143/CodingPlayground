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

vector<float> rotate3DQuarternion(vector<float> vec3, vector<float> axis, float rad) {
    vector<float> q(4, 0), v(4, 0), c(4, 0);
    // Create quarternion    
    q[0] = cos(rad / 2);
    q[1] = axis[0] * sin(rad / 2);
    q[2] = axis[1] * sin(rad / 2);
    q[3] = axis[2] * sin(rad / 2);
    // Create conjugate
    for (int i = 0; i < 4; i++)
        if (i == 0)
            c[i] = q[i];
        else
            c[i] = -1 * q[i];
    // Create V from input vector
    v[0] = 0;
    for (int i = 1; i < 4; i++)
        v[i] = vec3[i - 1];
    // Product q * v
    q = productQuarternion(q, v);
    // Product (q * v) * c
    q = productQuarternion(q, c);

    vec3[0] = q[1];
    vec3[1] = q[2];
    vec3[2] = q[3];
    return vec3;
}

int main() {
    vector<float> vec3(3, 0), axis(3, 0);
    float rad;
    cout << "Vector and rotation radian: ";
    cin >> vec3[0] >> vec3[1] >> vec3[2];
    cin >> rad;
    cout << endl << "Rotation axis: ";
    cin >> axis[0] >> axis[1] >> axis[2];
    
    rad = (rad / 180) * M_PI;
    vec3 = rotate3DQuarternion(vec3, axis, rad);
    cout << "(" << vec3[0] << ", " << vec3[1] << ", " << vec3[2] << ")" << endl;
    return 0;
}