#include <iostream>
using namespace std;
int n, a[24][24], dp[24][24][3];//3차원(가로, 세로, 대각선)//
bool check(int y, int x, int d) {
    //벽이 있는지 check!!//
    //가로 세로//
    if (d == 0 || d == 2) {
        if (!a[y][x]) return true;
    }
    //대각선//
    else if(d==1) {
        if (a[y][x] == 0 && a[y - 1][x] == 0 && a[y][x - 1] == 0) {
            return true;
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    dp[1][2][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            //가로//
            if (check(i, j + 1, 0)) dp[i][j + 1][0] += dp[i][j][0];
            if (check(i + 1, j + 1, 1))dp[i + 1][j + 1][1] += dp[i][j][0];
            //세로//
            if (check(i + 1, j, 2)) dp[i + 1][j][2] += dp[i][j][2];
            if (check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][2];

            //대각선//
            if (check(i, j + 1, 0)) dp[i][j + 1][0] += dp[i][j][1];
            if (check(i + 1, j, 2)) dp[i + 1][j][2] += dp[i][j][1];
            if (check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][1];

        }
    }
    int ret = dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
    cout << ret << '\n';
    return 0;
}

