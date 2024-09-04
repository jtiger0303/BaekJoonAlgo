#include <iostream>
#include <queue>
#include <tuple>
#include <string>
#include <algorithm>
using namespace std;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, visited[55][55], board[55][55];
queue<pair<int, int>> q;
string s;
void bfs(int y, int x) {
    visited[y][x] = 0;
    q.push({ y, x });

    while (q.size()) {
        tie(y, x) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            if (board[ny][nx] == 1) {
                // 흰 방일 때
                if (visited[ny][nx] > visited[y][x]) {
                    visited[ny][nx] = visited[y][x];
                    q.push({ ny, nx });
                }
            }
            else {
                // 검은 방일 때
                if (visited[ny][nx] > visited[y][x] + 1) {
                    visited[ny][nx] = visited[y][x] + 1;
                    q.push({ ny, nx });
                }
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

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) {
            board[i][j] = s[j] - 48;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = 987654321;
        }
    }
    bfs(0, 0);
    cout << visited[n - 1][n - 1] << '\n';
    return 0;
}
