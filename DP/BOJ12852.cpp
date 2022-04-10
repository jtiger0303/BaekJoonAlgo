#include <iostream>
using namespace std;
int dp[100001], n;
void go(int here) {
    if (here == 0) return;
    cout << here << ' ';
    if (here % 3 == 0 && dp[here] == (dp[here / 3] + 1)) go(here / 3);
    else if (here % 2 == 0 && dp[here] == (dp[here / 2] + 1)) go(here / 2);
    else if((here-1)>=0&&(dp[here]==(dp[here-1]+1))) go(here-1);
    return;
}
int main()
{
    cin >> n;

    dp[1] == 0;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
            dp[i] = dp[i / 3] + 1;
        }
        if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
            dp[i] = dp[i / 2] + 1;
        }
    }
    cout << dp[n] << '\n';
    go(n);
    return 0;
}
