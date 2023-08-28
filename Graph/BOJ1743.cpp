#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, m, k, visited[101][101], board[101][101], y, x;
vector<int> v;
int dfs(int y, int x) {
    int ret = 1;
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || board[ny][nx] !=1) continue;
        ret += dfs(ny, nx);
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;

    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        board[x-1][y-1] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1 && !visited[i][j]) {
                v.push_back(dfs(i, j));
            }
        }
    }
    sort(v.begin(), v.end());
    cout << v[v.size() - 1] << '\n';
    return 0;
}

