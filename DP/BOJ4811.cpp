﻿#include <iostream>
using namespace std;
typedef long long LL;
LL n, dp[31][31];
LL go(int whole, int not_whole) {
    if (whole == 0 && not_whole == 0) return 1;
    if (dp[whole][not_whole]) return dp[whole][not_whole];
    LL& ret = dp[whole][not_whole];
    if (whole > 0) ret += go(whole - 1, not_whole + 1);//온전한 걸 먹으면, 반쪽 짜리 늠//
    if (not_whole > 0) ret += go(whole, not_whole - 1);
    return ret;
}
int main()
{
    while (true) {
        cin >> n;
        if (n == 0) break;
        cout << go(n, 0) << '\n';
    }
    return 0;
}

