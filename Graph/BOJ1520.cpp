#include <iostream>
using namespace std;
int visited[501][501], board[501][501];
int m, n, ret, dp[501][501];
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int dfs(int y, int x) {
    if (y == m - 1 && x == n - 1) return 1;
    if (visited[y][x]) return dp[y][x];

    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
        if (board[ny][nx] >= board[y][x]) continue;
        dp[y][x] += dfs(ny, nx);
    }
    return dp[y][x];
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
    cout << dfs(0, 0) << '\n';
    return 0;
}

