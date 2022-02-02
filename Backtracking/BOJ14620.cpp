#include <iostream>
#include <algorithm>
using namespace std;
int n, ret = 987654321, v[20][20], p[20][20];
const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, 1, 0, -1 };
int setflower(int y, int x) {
    v[y][x] = 1;
    int s = p[y][x];
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        v[ny][nx] = 1;
        s += p[ny][nx];
    }
    return s;
}
bool check(int y, int x) {
    if (v[y][x]) return 0;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n || v[ny][nx]) return 0;
    }
    return 1;
}
void eraseflower(int y, int x) {
    v[y][x] = 0;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        v[ny][nx] = 0;
    }
}
void flower(int cnt, int hap) {
    if (cnt == 3) {
        ret = min(ret, hap);
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (check(i, j)) {
                flower(cnt + 1, hap + setflower(i, j));//가격을 넘긴다//
                eraseflower(i, j);
                //visited=1, g0, visited=0
            }
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> p[i][j];
        }
    }
    flower(0, 0);
    cout << ret << '\n';
}
