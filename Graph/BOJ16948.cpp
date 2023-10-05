#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
const int dy[] = { -1, 1, 2, 1, -1, -2 };
const int dx[] = { -2, -2, 0, 2, 2, 0 };
int n, visited[201][201];
queue<pair<int, int>> q;
void bfs(int y, int x) {
    visited[y][x] = 1;
    q.push({ y, x });

    while (q.size()) {
        tie(y, x) = q.front();
        q.pop();

        for (int i = 0; i < 6; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) continue;
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

    int a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    bfs(b, a);

    if (!visited[d][c]) {
        cout << -1 << '\n';
    }
    else {
        cout << visited[d][c]-1 << '\n';
    }
    return 0;
}

