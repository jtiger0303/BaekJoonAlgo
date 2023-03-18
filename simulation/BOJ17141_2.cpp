#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int n, m;
int a[51][51], visited[51][51];
bool check[51][51]; //바이러스 놓았는지 확인
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
queue<pair<int, int>> q;
vector<pair<int, int>> virusList;
int mini = 987654321;
bool spread() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != 1 && !visited[i][j]) return false;
        }
    }
    return true;
}
int bfs() {
    int res = 0;
    memset(visited, 0, sizeof(visited));

    for (pair<int, int> b : virusList) {
        visited[b.first][b.second] = 0;
        q.push({ b.first, b.second });
    }
    while (q.size()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx] || a[ny][nx] == 1) continue;
            visited[ny][nx] = visited[y][x] + 1;
            res = visited[ny][nx];
            q.push({ ny, nx });
        }
    }
    return res;
}
//**바이러스 위치 조합 구하기**//
void dfs(int y, int x, int cnt) {
    if (cnt == m) {
        int res = bfs();
        if (spread()) {
            if (mini > res) {
                mini = res;
            }
        }
        return;
    }
    for (int i = y; i < n; i++) {
        for (int j = x; j < n; j++) {
            if (a[i][j] != 2 || check[i][j]) continue;
            check[i][j] = true;
            virusList.push_back({ i, j });
            dfs(i, j, cnt + 1);
            check[i][j] = false;
            virusList.pop_back();
        }
        x = 0;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    dfs(0, 0, 0);
    if (mini == 987654321) {
        mini = -1;
    }
    cout << mini << '\n';
    return 0;
}

