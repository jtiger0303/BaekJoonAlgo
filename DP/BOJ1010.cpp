#include <iostream>
using namespace std;
int t, n, m;
int dp[30][30];
int combination(int m, int n) { //mCn, 시간초과가 나므로 dp사용~~
    if (dp[m][n] != 0) {
        return dp[m][n];
    }
    if (m == n || n == 0) {
        dp[m][n] = 1;
        return dp[m][n];
    }
    else {
        dp[m][n]=combination(m - 1, n - 1) + combination(m - 1, n);
        return dp[m][n];
    }
        
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while (t--) {
        cin >> n >> m;
        cout << combination(m, n) << '\n';
    }
    return 0;
}

