#include <iostream>
#include <vector>
using namespace std;

void printArr(int area[1000][1000], int x, int y) {
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            cout << area[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int area[1000][1000] = {0}, n;
    int ans[1001] = {0};
    cin >> n;
    for (int i = 0; i < n; i++) {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        lx--;
        ly--;
        rx--;
        ry--;
        area[ly][lx] += 1;
        area[ry][rx] += 1;
        area[ry][lx] -= 1;
        area[ly][rx] -= 1;
        // calc horizotal direction
        for (int i = ly; i <= ry; i++) {
            for (int j = lx; j < rx; j++) {
                area[i][j + 1] += area[i][j];
            }
        }
        // calc vertical direction
        for (int i = lx; i <= rx; i++) {
            for (int j = ly; j < ry; j++) {
                area[j + 1][i] += area[j][i];
            }
        }
    }

    printArr(area, 10, 10);
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            if (area[i][j] > 0)
                ans[area[i][j] - 1]++;
        }
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << endl;
    return 0;
}