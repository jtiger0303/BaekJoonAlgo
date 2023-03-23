#include <iostream>
#include <map>
using namespace std;
int r, c, t;
int board[55][55], tmp[55][55];
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int airCleaner;
void dust() {
    for (int i = 0; i < r; i++) {
        fill(tmp[i], tmp[i] + c, 0);
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] > 0) {
                int cnt = 0;
                int plus = board[i][j] / 5; //확산되는 먼지 양
                for (int dir = 0; dir < 4; dir++) {
                    int ny = i + dy[dir];
                    int nx = j + dx[dir];

                    if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
                    if (board[ny][nx] == -1) continue; //주변에 공기청정기가 있을 경우
                    cnt++;
                    tmp[ny][nx] += plus;

                }
                tmp[i][j] += (board[i][j] - plus * cnt);
            }
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            board[i][j] = tmp[i][j];
        }
    }
    board[airCleaner][0] = -1;
    board[airCleaner + 1][0] = -1;
}
void clean() {
    for (int i = airCleaner - 1; i >= 0; i--)
    {
        if (board[i + 1][0] == -1) continue;

        board[i + 1][0] = board[i][0];
    }

    for (int i = 1; i < c; i++)
    {
        if (board[0][i - 1] == -1) continue;

        board[0][i - 1] = board[0][i];
    }

    for (int i = 1; i <= airCleaner; i++)
    {
        board[i - 1][c - 1] = board[i][c - 1];
    }

    for (int i = c - 2; i >= 1; i--)
    {
        board[airCleaner][i + 1] = board[airCleaner][i];
    }
    board[airCleaner][1] = 0;

    int airCleaner_D = airCleaner + 1;

    for (int i = airCleaner_D + 1; i < r - 1; i++)
    {
        board[i][0] = board[i + 1][0];
    }

    for (int i = 0; i < c - 1; i++)
    {
        board[r - 1][i] = board[r - 1][i + 1];
    }

    for (int i = r - 1; i > airCleaner_D; i--)
    {
        board[i][c - 1] = board[i - 1][c - 1];
    }

    for (int i = c - 1; i > 1; i--)
    {
        board[airCleaner_D][i] = board[airCleaner_D][i - 1];
    }
    board[airCleaner_D][1] = 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c >> t;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < r; i++) {
        if (board[i][0] == -1) {
            airCleaner = i;
            break;
        }
    }

    while (t--) {
        dust();
        clean();
    }

    int ans = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] == -1) continue;
            ans += board[i][j];
        }
    }
    cout << ans << '\n';
    return 0;
}

