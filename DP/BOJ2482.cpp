#include <iostream>
using namespace std;
int n, k;
const int mod = 1000000003;
int dp[1004][1004];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1; //i개 중 0개 선택
        dp[i][1] = i; //i개 중 1개 선택
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= k; j++) {
            dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j])%mod;
        }
    }
    cout << (dp[n - 1][k] + dp[n - 3][k - 1]) % mod << '\n'; //첫번째 색깔 선택시 해당 색과 인접한 두 색 선택 X
    return 0;
}

