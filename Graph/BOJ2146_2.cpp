#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <tuple>
using namespace std;
int n, a[101][101], ans = 987654321, temp;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
vector<pair<int, int>> v; //모서리 저장
queue<pair<int, int>> q;
void calculate() {
    //거리 계산: 세로의 길이의 차+가로의 길이 차+1
    for (int i = 0; i < v.size() - 1; i++) {
        int yy = v[i].first;
        int xx = v[i].second;

        for (int j = i + 1; j < v.size(); j++) {
            int ny = v[j].first;
            int nx = v[j].second;
            if (a[yy][xx] > 0 && a[ny][nx] > 0 && a[yy][xx] != a[ny][nx]) {
                temp = abs(yy - ny) + abs(xx - nx) - 1;
                if (ans > temp) ans = temp;
            }
        }
    }
}
void labeling(int y, int x, int cnt) {
    q.push({ y, x });

    while (q.size()) {
        bool edge = false;
        tie(y, x) = q.front();
        a[y][x] = cnt; //라벨링
        q.pop();

        for (int i = 0; i < 4; i++) {
            
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            if (a[ny][nx] < 0) {
                a[ny][nx] = cnt;
                q.push({ ny, nx });
            }
            else if (a[ny][nx] == 0) {
                edge = true; //모서리가 닿은 부분이 0이라면
            }
        }
        if (edge) v.push_back({ y, x });
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] != 0) {
                a[i][j] = -1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] < 0) {
                labeling(i, j, cnt++);
            }
        }
    }
    calculate();
    cout << ans << '\n';
    return 0;

}

