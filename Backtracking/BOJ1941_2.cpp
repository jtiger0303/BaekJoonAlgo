#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
#include <tuple>
#include <string>
#include <algorithm>
using namespace std;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
char seat[5][5];
int visited[5][5], board[5][5], y, x;
int ret = 0;
int pos[25] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1 };
queue<pair<int, int>> q;
string s;
bool bfs(vector<pair<int, int>> v) {
    //v에 담긴 좌표들이 서로 이여져있는지 확인하는 함수
    fill(&visited[0][0], &visited[4][5], 0); //방문 표시 배열과 board를 0으로 초기화
    fill(&board[0][0], &board[4][5], 0);

    for (auto c : v) {
        board[c.first][c.second] = 1; //각 좌표들의 위치를 board에 1로 표시
    }

    q.push({ v[0].first, v[0].second }); // bfs의 시작점은 첫 번째 좌표
    visited[v[0].first][v[0].second] = 1;

    while (q.size()) {
        tie(y, x) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5) continue;
            if (board[ny][nx] != 1 || visited[ny][nx]) continue;
            visited[ny][nx] = 1;
            q.push({ ny, nx });
        }
    }
    for (auto c : v) {
        //좌표들 중 방문하지 않은 것이 있다면 false 반환
        if (!visited[c.first][c.second]) return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 5; i++) {
        cin >> s;
        for (int j = 0; j < 5; j++) {
            seat[i][j] = s[j];
        }
    }

    do {
        vector<pair<int, int>> v;

        for (int i = 0; i < 25; i++) {
            if (pos[i] == 1) v.push_back({ (i / 5), (i % 5) }); //선택한 좌표 저장

        }
        bool conn = bfs(v); //bfs로 선택한 좌표들이 이어지는 지 확인
        if (conn) {
            //선택한 좌표들이 이어진다면
            int cnt = 0;
            for (auto c : v) {
                if (seat[c.first][c.second] == 'S') cnt++;
            }
            if (cnt >= 4) ret++;
        }

    } while (next_permutation(pos, pos + 25));
    cout << ret << '\n';
    return 0;
}

