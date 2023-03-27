#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
int n, m;
int visited[1002][1002][2];
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
queue<pair<pair<int, int>, int>> q;
int bfs(int y, int x, vector<string>& graph) {
    visited[0][0][1] = 1;
    q.push({ { 0, 0 }, 1 });

    while (q.size()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int block = q.front().second;// 부술수 있는 벽
        q.pop();

        if (y == n - 1 && x == m - 1) {
            return visited[y][x][block];
        }
        
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (graph[ny][nx] == '1' && block) {
                //이동할 수 없는 벽이 있고 부술 수 있다면
                visited[ny][nx][block - 1] = visited[y][x][block] + 1;
                q.push({ {ny, nx}, 0 });
            }
            else if (graph[ny][nx] == '0' && !visited[ny][nx][block]) {
                //아직 방문하지 않은 곳이라면
                visited[ny][nx][block] = visited[y][x][block] + 1;
                q.push({ { ny, nx }, block });
            }
        }
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    vector<string> wall(n);
    for (int i = 0; i < n; i++) {
        cin >> wall[i];
    }
    cout << bfs(0, 0, wall) << '\n';
    return 0;
}

