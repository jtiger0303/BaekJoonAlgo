#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
queue<pair<int, int>> q;
char board[605][605];
int visited[605][605], n, m;
int ret;
void bfs(int y, int x) {
    visited[y][x] = 1;
    q.push({ y, x });
    
    while (q.size()) {
        tie(y, x) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || board[ny][nx] == 'X') continue;
            if (board[ny][nx] == 'P') ret++;
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
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'I') {
                bfs(i, j);
            }
        }
    }

    if (ret == 0) {
        cout << "TT" << '\n';
    }
    else {
        cout << ret << '\n';
    }
    return 0;
}

