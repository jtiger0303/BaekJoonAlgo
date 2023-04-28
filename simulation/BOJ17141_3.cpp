#include <iostream>
#include <cstring>
#include <tuple>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, m, visited[51][51], board[51][51], y, x, total=0;
int mini = 987654321;
int visit[51][51];
queue<pair<int, int>> q;
vector<pair<int, int>> virusList, ret;
void bfs() {
    memset(visited, 0, sizeof(visited));

    for (pair<int, int> b : ret) {
        //조합으로 나온 바이러스의 개수를 큐에 삽입
        visited[b.first][b.second] = 1;
        q.push({ b.first, b.second });
    }

    int cnt = 0, tmp=0;

    while (q.size()) {
        tie(y, x) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx] || board[ny][nx] == 1) continue;
            visited[ny][nx] = visited[y][x] + 1;
            cnt++;
            tmp = visited[ny][nx]-1;
            q.push({ ny, nx });
        }
        if (total - m == cnt) {
            mini = min(mini, tmp);
        }
    }
}
void dfs(int idx, int cnt) {
    //바이러스의 개수 m개를 조합으로 구하기
    if (cnt == m) {
        bfs();
        return;
    }

    for (int i = idx; i < virusList.size(); i++) {
        if (visit[virusList[i].first][virusList[i].second]) continue;
        visit[virusList[i].first][virusList[i].second] = 1;
        ret.push_back({ virusList[i].first, virusList[i].second });
        dfs(i, cnt + 1);
        ret.pop_back();
        visit[virusList[i].first][virusList[i].second] = 0;
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
            cin >> board[i][j];
            if (board[i][j] == 2) virusList.push_back({ i, j });
            if (board[i][j] != 1) total++;
        }
    }
    dfs(0, 0);
    if (mini != 987654321) {
        cout << mini << '\n';
    }
    else {
        cout << -1 << '\n';
    }
    return 0;
}

