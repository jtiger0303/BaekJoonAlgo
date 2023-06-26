#include <iostream>
using namespace std;
int n, m, r, board[302][302];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> r;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    //왼쪽->위->오른쪽->아래
    while (r--) {
        int y1 = 0, x1 = 0, y2 = n - 1, x2 = 0, y3 = n - 1, x3 = m - 1, y4 = 0, x4 = m - 1;
        while ((y1 < y2) && (x1 < x4)) {
            int tmp = board[y2][x2];
            for (int i = y2; i > y1; i--) {
                board[i][x2] = board[i - 1][x2];
            }
            for (int i = x1; i < x4; i++) {
                board[y1][i] = board[y1][i + 1];
            }
            for (int i = y4; i < y3; i++) {
                board[i][x4] = board[i + 1][x4];
            }
            for (int i = x3; i > x2; i--) {
                board[y3][i] = board[y3][i - 1];
            }
            board[y2][x2 + 1] = tmp;
            y1++;
            x1++;

            y2--;
            x2++;

            y3--;
            x3--;

            y4++;
            x4--;
        }

    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j]<<' ';
        }
        cout << '\n';
    }

}

