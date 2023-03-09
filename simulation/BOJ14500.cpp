#include <iostream>
#include <algorithm>
using namespace std;
int n, m, a[502][502];
int visited[502][502], ans;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
void dfs(int y, int x, int depth, int sum) {
    if (depth == 3) {
        ans = max(ans, sum);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (visited[ny][nx]) continue;
        //원복
        visited[ny][nx] = 1;
        dfs(ny, nx, depth + 1, sum + a[ny][nx]);
        visited[ny][nx] = 0;
    }
}
void shape1(int r, int c) {
    int sum = 0;
    sum = a[r][c] + a[r][c + 1] + a[r][c + 2] + a[r - 1][c + 1];
    ans = max(ans, sum);
}
void shape2(int r, int c) {
    int sum = 0;
    sum = a[r][c] + a[r][c + 1] + a[r][c + 2] + a[r + 1][c + 1];
    ans = max(ans, sum);
}
void shape3(int r, int c) {
    int sum = 0;
    sum = a[r][c] + a[r+1][c] + a[r+2][c] + a[r + 1][c + 1];
    ans = max(ans, sum);
}
void shape4(int r, int c) {
    int sum = 0;
    sum = a[r][c] + a[r-1][c + 1] + a[r][c + 1] + a[r + 1][c + 1];
    ans = max(ans, sum);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ans = 0;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = 1;
            dfs(i, j, 0, a[i][j]);
            visited[i][j] = 0;
            if (i - 1 >= 0 && j + 2 < m) shape1(i, j);
            if (j + 2 < m && i + 1 < n) shape2(i, j);
            if (i + 2 < n && j + 1 < m) shape3(i, j);
            if (i + 1 < n && i - 1 >= 0 && j + 1 < m) shape4(i, j);
        }
    }
    cout << ans << '\n';
    return 0;
}

