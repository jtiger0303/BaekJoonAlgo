#include <iostream>
#include <algorithm>
using namespace std;
int r, c;
int ans = 0;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
char board[21][21];
int alpha[26] = { 0 };
void dfs(int y, int x, int cnt) {
    ans = max(ans, cnt);
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (nx < 0 || ny < 0 || nx >= c || ny >= r) continue;
        
        int k = (int)board[ny][nx] - 'A';
        if (alpha[k]) continue; // 방문했었던 알파벳인 경우 패스
        alpha[k]++;
        dfs(ny, nx, cnt + 1);
        alpha[k]--;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> board[i][j];
        }
    }
    alpha[(int)board[0][0] - 'A']++; //(0,0) 추가
    dfs(0, 0, 1);
    cout << ans << '\n';
    return 0;
}
----------------------------------<2.완전탐색>----------------------------------------
#include <iostream>
using namespace std;
int R, C, ret, visited[30];
char a[21][21];
const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, 1, 0, -1 };
void go(int y, int x, int cnt) {
    ret = max(ret, cnt);
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
        int next = (int)(a[ny][nx] - 'A');
        if (!visited[next]) {
            visited[next] = 1;
            go(ny, nx, cnt + 1);
            visited[next] = 0;//완전탐색//
        }
    }
    return;
}
int main()
{
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> a[i][j];
        }
    }
    visited[(int)a[0][0] - 'A'] = 1;
    go(0, 0, 1);
    cout << ret << '\n';
    return 0;
}

