#include <iostream>
#include <vector>
#include <map>
using namespace std;
int a[104][104], visited[104][104];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int n, m, cnt, cnt2;
vector<pair<int, int>> v;
void go(int y, int x) {//바깥에서 한 번
    if (a[y][x] == 1) {
        v.push_back({ y, x });
        return;
    }
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
        visited[ny][nx] = 1;
        go(ny, nx);
    }
    return;
}
int main()
{
    cnt = 0;
    cnt2 = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    while (true) {
        cnt2 = 0;
        fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
        v.clear();

        //visited[0][0]=1;
        go(0, 0);
        for (pair<int, int> b : v) {
            if (a[b.first][b.second] == 1) cnt2++;
        }
        for (pair<int, int> b : v) {
            a[b.first][b.second] = 0;
        }
        cnt++;
        int flag = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] != 0) flag = 1;
            }
        }
        if (!flag) break;

    }
    cout << cnt << '\n';
    cout << cnt2 << '\n';

}
