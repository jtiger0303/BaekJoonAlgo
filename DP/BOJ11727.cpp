﻿#include <iostream>
using namespace std;
int dp[1001], n;
int main()
{
    cin >> n;

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i - 1] + 2 * dp[i - 2]);
        dp[i] %= 10007;
    }
    cout << dp[n] << '\n';
    return 0;
}

