#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9;
int n, m, board[104][104];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == j) board[i][j] = 0;
            else board[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int st, en, cost;
        cin >> st >> en >> cost;
        board[st][en] = min(board[st][en], cost);
    }

    // k: 거쳐가는 노드
    for (int k = 1; k <= n; k++) {
        // i: 시작 노드
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (board[i][k] + board[k][j] < board[i][j]) {
                    board[i][j] = board[i][k] + board[k][j];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (board[i][j] == INF) cout << "0 ";
            else cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
