#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <string>
using namespace std;
int n, m, board[104][104], visited[104][104];
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1};
const int INF = 987654321;
vector<vector<int>> dist(104, vector<int>(101, INF));
queue<pair<int, int>> q;
string s;
void bfs(int y, int x) {
    dist[y][x] = 0;
    q.push({ y, x });

    while (q.size()) {
        tie(y, x) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (board[ny][nx] == 1 && (dist[ny][nx] > dist[y][x] + 1)) {
                // 벽이 있을 경우
                dist[ny][nx] = dist[y][x] + 1;
                q.push({ ny, nx });
            }
            else if (board[ny][nx] == 0 && (dist[ny][nx] > dist[y][x])) {
                dist[ny][nx] = dist[y][x];
                q.push({ ny, nx });
            }
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

    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            board[i][j] = s[j] - 48;
        }
    }

    bfs(0, 0);

    cout << dist[n - 1][m - 1] << '\n';
    return 0;
}
