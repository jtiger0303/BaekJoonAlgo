#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n, m;
int dp[1004][1004];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    string str;

    for (int i = 1; i <= n; i++) {
        cin >> str;
        for (int j = 0; j < m; j++) {
            dp[i][j + 1] = str[j] - 48;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dp[i][j] != 0) {
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                ans = max(dp[i][j], ans);
            }
        }
    }
    cout << ans * ans << '\n';
    return 0;
}

