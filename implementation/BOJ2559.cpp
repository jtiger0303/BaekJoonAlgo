﻿#include <iostream>
using namespace std;
int n, k, temp, psum[100001], ret = -1000004;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        //psum(구간합)은 1부터~~//
        cin >> temp;
        psum[i] = psum[i - 1] + temp;
    }
    for (int i = k; i <= n; i++) {
        ret = max(ret, psum[i] - psum[i - k]);
    }
    cout << ret << '\n';
    return 0;
}

