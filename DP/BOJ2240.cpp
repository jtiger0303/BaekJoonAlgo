﻿#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[1004][2][34], n, m, b[1004];
int go(int idx, int tree, int cnt) {
    //idx=자두의 위치, tree=나의 위치, cnt=몇 번 움직일 수 있나//
    //기저사례//
    if (cnt < 0) return -1e9;
    if (idx == n) return 0;
    //메모이제이션//
    int& ret = dp[idx][tree][cnt];
    if (~ret) return ret;
    //로직//
    return ret = max(go(idx + 1, tree ^ 1, cnt - 1), go(idx + 1, tree, cnt)) + (tree == b[idx] - 1);//움직이거나, 안 움직이거나, tree가 맞는지//

}
int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> b[i];
    cout << max(go(0, 1, m - 1), go(0, 0, m)) << '\n';
    return 0;
}

