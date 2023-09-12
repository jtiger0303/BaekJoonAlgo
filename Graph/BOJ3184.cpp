#include <iostream>
using namespace std;
int r, c, visited[255][255];
char board[255][255];
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int wolf, sheep, totalw, totals;
void dfs(int y, int x) {
    visited[y][x] = 1;
    if (board[y][x] == 'o') {
        //양의 수
        sheep++;
    }
    if (board[y][x] == 'v') {
        //늑대의 수
        wolf++;
    }
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= r || nx < 0 || nx >= c || visited[ny][nx] || board[ny][nx] == '#') continue;
        dfs(ny, nx);
    }
    return;
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
            if (board[i][j] == 'o') {
                totals++;
            }
            if (board[i][j] == 'v') {
                totalw++;
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            //wolf = 0;
            //sheep = 0;
            if (board[i][j] != '#' && !visited[i][j]) {
                dfs(i, j);
            }
            if (wolf >= sheep) {
                //늑대가 양보다 많다면 잡아먹는다
                totals -= sheep;
            }
            else if (wolf < sheep) {
                totalw -= wolf;
            }
        }
    }
    cout << totals << ' ' << totalw;
    return 0;

}

