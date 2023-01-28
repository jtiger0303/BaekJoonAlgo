#include <iostream>
#include <algorithm>
using namespace std;
int n, dp[301][3];
int stairs[301];
//dp[i][j]=현재까지 j개의 계단을 연속해서 밟고 i번째 계단까지 올라섰을 때 점수합의 최댓값
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> stairs[i];
    }
    if (n == 1) {
        cout << stairs[1];
        return 0;
    }
    dp[1][1] = stairs[1];
    dp[1][2] = 0;
    dp[2][1] = stairs[2];
    dp[2][2] = stairs[1] + stairs[2];

    for (int i = 3; i <= n; i++) {
        dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + stairs[i];
        dp[i][2] = dp[i - 1][1] + stairs[i];
    }
    cout << max(dp[n][1], dp[n][2]);
    return 0;
}

