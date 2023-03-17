#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int n, m, a[10][10], ret;
int visited[10][10];
vector<pair<int, int>> wallList, virusList;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
void dfs(int y, int x) {
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m||visited[ny][nx]||a[ny][nx]==1) continue;
        visited[ny][nx] = 1;
        dfs(ny, nx);
    }
    return;
}
int solve() {
    memset(visited, 0, sizeof(visited));

    for (pair<int, int> b : virusList) {
        visited[b.first][b.second] = 1;
        dfs(b.first, b.second);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //바이러스가 퍼지지 않은 안전지역
            if (a[i][j] == 0 && !visited[i][j]) cnt++;
        }
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 2) virusList.push_back({ i, j });
            if (a[i][j] == 0) wallList.push_back({ i, j });
        }
    }

    for (int i = 0; i < wallList.size(); i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < j; k++) {
                //경우의 수 3가지
                a[wallList[i].first][wallList[i].second] = 1;
                a[wallList[j].first][wallList[j].second] = 1;
                a[wallList[k].first][wallList[k].second] = 1;
                ret = max(ret, solve());
                a[wallList[i].first][wallList[i].second] = 0;
                a[wallList[j].first][wallList[j].second] = 0;
                a[wallList[k].first][wallList[k].second] = 0;
            }
        }
    }
    cout << ret << '\n';
    return 0;
}

