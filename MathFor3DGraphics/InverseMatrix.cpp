#include<iostream>
#include<vector>
using namespace std;

vector<vector<float>> inverse3x3Matrix(vector<vector<float>> mat3) {
    vector<vector<float>> adj(3, vector<float>(3));
    float det = mat3[0][0] * mat3[1][1] * mat3[2][2] + mat3[0][1] * mat3[1][2] * mat3[2][0] + mat3[0][2] * mat3[2][1] * mat3[1][0]
                - mat3[2][0] * mat3[1][1] * mat3[0][2] - mat3[2][1] * mat3[1][2] * mat3[0][0] - mat3[2][2] * mat3[1][0] * mat3[0][1];
    if (det == 0) {
        cout << "No inverse matrix exists" << endl;
        return mat3;
    }
    adj[0][0] = mat3[1][1] * mat3[2][2] - mat3[1][2] * mat3[2][1];
    adj[0][1] = -1 * (mat3[1][0] * mat3[2][2] - mat3[2][0] * mat3[1][2]);
    adj[0][2] = mat3[1][0] * mat3[2][1] - mat3[2][0] * mat3[1][1];
    adj[1][0] = -1 * (mat3[0][1] * mat3[2][2] - mat3[0][2] * mat3[2][1]);
    adj[1][1] = mat3[0][0] * mat3[2][2] - mat3[2][0] * mat3[0][2];
    adj[1][2] = -1 * (mat3[0][0] * mat3[2][1] - mat3[0][1] * mat3[2][0]);
    adj[2][0] = mat3[0][1] * mat3[1][2] - mat3[1][1] * mat3[0][2];
    adj[2][1] = -1 * (mat3[0][0] * mat3[1][2] - mat3[1][0] * mat3[0][2]);
    adj[2][2] = mat3[0][0] * mat3[1][1] - mat3[1][0] * mat3[0][1];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            mat3[i][j] = adj[j][i] / det;
    return mat3;
}

int main() {
    vector<vector<float>> mat3(3, vector<float>(3)), inv(3, vector<float>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> mat3[i][j];
        }
    }
    cout << "=== inverse matrix ===" << endl;
    inv = inverse3x3Matrix(mat3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << inv[i][j] << " ";
        }
        cout << endl;
    }
    cout << "=== confirmation ===" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            float tmp = 0;
            for (int k = 0; k < 3; k++) {
                 tmp += mat3[i][k] * inv[k][j] + 10;
             }
            cout << tmp - 30 << " ";
        }
        cout << endl;
    }
    return 0;
}