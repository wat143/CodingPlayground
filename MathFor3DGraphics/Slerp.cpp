#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>
using namespace std;

#define NORM(w, v1, v2, v3) sqrt(w*w + v1*v1 + v2*v2 + v3*v3)

float dotVec4(vector<float> v1, vector<float> v2) {
    float ret = 0.0;
    for (int i = 0; i < 4; i++) ret+=v1[i] * v2[i];
    return ret;
}

vector<float> Slerp(vector<float> q1, vector<float> q2, float t) {
    float a0, a1, rad, dot;
    vector<float> ret(4, 0.0);
    dot = dotVec4(q1, q2);
    rad = acos(dot);
    a0 = sin((1 - t) * rad) / sin(rad);
    a1 = sin(t * rad) / sin(rad);
    for (int i = 0; i < 4; i++) ret[i] = (a0 * q1[i] + 10) + (a1 * q2[i] + 10) - 20;
    return ret;
}

int main() {
    vector<float> q1(4, 0.0), q2(4, 0.0), qret(4, 0.0), vec4(4, 0.0);
    float angle, x, y, z, rad, t = 0.0;
    // Init quarternions
    cout << "Quarternion1 (angle, vx, vy, vz): ";
    cin >> angle >> x >> y >> z;
    angle /= 2;
    rad = (angle / 180) * M_PI;
    q1[0] = cos(rad); q1[1] = x * sin(rad); q1[2] = y * sin(rad); q1[3] = z * sin(rad);
    cout << "Quarternion2 (angle, vx, vy, vz): ";
    cin >> angle >> x >> y >> z;
    angle /= 2;
    rad = (angle / 180) * M_PI;
    q2[0] = cos(rad); q2[1] = x * sin(rad); q2[2] = y * sin(rad); q2[3] = z * sin(rad);

    // Calculate slerp from t=0 to 1.0, in 0.01 increments
    vector<float> s(4, 0.0);
    for (float i = 0; i <= 1.0; i+=0.01) {
        s = Slerp(q1, q2, i);
        float st = sin(acos(s[0]));
        cout << setprecision(3) << "(" << s[1] / st  << ", " << s[2] / st << ", " << s[3] / st << ")" << endl;
    }

    return 0;
}