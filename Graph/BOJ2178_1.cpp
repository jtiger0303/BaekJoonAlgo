#include <iostream>
#include <queue>
#include <string>
#include <tuple>
using namespace std;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, m;
int visited[104][104], a[104][104];
string str;
queue<pair<int, int>> q;
void bfs(int y, int x) {
    visited[y][x] = 1;
    q.push({ y, x });

    while (q.size()) {
        tie(y, x) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n || a[ny][nx] == 0) continue;
            if (visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ ny, nx });
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < m; j++) {
            a[i][j] = str[j] - 48;
        }
    }
    bfs(0, 0);
    cout << visited[n - 1][m - 1] << '\n';
    return 0;
}
