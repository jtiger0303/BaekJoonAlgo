#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, m, visited[102][102], x, y, a, b, sx, sy, board[102][102];
queue<pair<int, int>> q;
vector<pair<int, int>> v[102][102];
bool isc(pair<int, int> next) {
    for (int i = 0; i < 4; i++) {
        int ny = next.first + dy[i];
        int nx = next.second + dx[i];

        if (ny < 1 || ny > n || nx < 1 || nx > n) continue;
        if (visited[ny][nx]) return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    fill(&board[0][0], &board[0][0] + 102 * 102, 0);
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> a >> b;
        v[y][x].push_back({ b, a });
    }

    visited[1][1] = 1;
    board[1][1] = 1;
    q.push({ 1, 1 });

    while (q.size()) {
        tie(sy, sx) = q.front();
        q.pop();

        for (auto c : v[sy][sx]) {
            if (visited[c.first][c.second]) continue;
            if (c.first < 1 || c.first > n || c.second < 1 || c.second > n) continue;
            if (isc(c)) {
                visited[c.first][c.second] = 1;
                q.push({ c.first, c.second });
            }
            board[c.first][c.second] = 1;
        }

        for (int i = 0; i < 4; i++) {
            int ny = sy + dy[i];
            int nx = sx + dx[i];

            if (ny < 1 || ny > n || nx < 1 || nx > n || board[ny][nx] == 0) continue;
            if (visited[ny][nx]) continue;
            visited[ny][nx] = visited[sy][sx] + 1;
            q.push({ ny, nx });
        }
    }
    int sum = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sum += board[i][j];
        }
    }
    cout << sum << '\n';
    return 0;
}

