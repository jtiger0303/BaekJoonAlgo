#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int visited[501][501];
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int picture[501][501];
int width;
int mWidth;
void dfs(int y, int x) {
    visited[y][x] = 1;
    width++;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (picture[ny][nx] == 1 && !visited[ny][nx]) {
            dfs(ny, nx);
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> picture[j][i];
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[j][i] && picture[j][i] == 1) {
                cnt++;
                width = 0;
                dfs(j, i);
                mWidth = max(mWidth, width);
            }
        }
    }
    cout << cnt << '\n' << mWidth;
    return 0;
}

