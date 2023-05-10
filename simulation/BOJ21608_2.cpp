#include <iostream>
using namespace std;
int n, student, board[22][22], arr[401][4];
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int countLike(int y, int x, int s) {
    int ret = 0;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

        for (int j = 0; j < 4; j++) {
            if (board[ny][nx] == arr[s][j]) {
                ret++;
                break;
            }
        }
    }
    return ret;
}
int countEmpty(int y, int x) {
    int ret = 0;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if (board[ny][nx] == 0) ret++;
    }
    return ret;
}
void find(int s) {
    int like = 0;
    int empty = -1;
    int fi;
    int fj;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j]) continue;

            int cl = countLike(i, j, s);
            int ce = countEmpty(i, j);

            if (like < cl) {
                //인접한 칸에 좋아하는 학생이 많은 순
                like = cl;
                empty = ce;
                fi = i;
                fj = j;
            }
            else if (like == cl) {
                //인접한 칸의 빈자리가 많은 순
                if (empty < ce) {
                    empty = ce;
                    fi = i;
                    fj = j;
                }
            }
        }
    }
    board[fi][fj] = s;
}
int solve() {
    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int s = board[i][j];
            int cnt = 0;

            for (int k = 0; k < 4; k++) {
                int ny = i + dy[k];
                int nx = j + dx[k];

                if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

                for (int l = 0; l < 4; l++) {
                    if (board[ny][nx] == arr[s][l]) {
                        cnt++;
                        break;
                    }
                }
            }
            if (cnt == 2) ret += 10;
            else if (cnt == 3) ret += 100;
            else if (cnt == 4) ret += 1000;
            else ret += cnt;
        }
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    student = n * n;

    int s;

    for (int i = 1; i <= student; i++) {
        cin >> s;
        for (int j = 0; j < 4; j++) {
            cin >> arr[s][j];
        }
        find(s);
    }
    cout << solve();
    return 0;
}

