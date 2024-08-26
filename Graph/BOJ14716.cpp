#include <iostream>
#include <vector>
using namespace std;
const int dy[] = { -1, 0, 1, 0, 1, 1, -1, -1 };
const int dx[] = { 0, 1, 0, -1, 1, -1, -1, 1 };
int n, m, visited[255][255], board[255][255], ret;
void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 8; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
        if (board[ny][nx] == 1 && !visited[ny][nx]) {
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

    cin >> m >> n;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1 && !visited[i][j]) {
                ret++;
                dfs(i, j);
            }
        }
    }
    cout << ret << '\n';
    return 0;
}

