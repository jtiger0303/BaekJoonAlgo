﻿#include <iostream>
using namespace std;
int n, l, a[104][104], b[104][104], ret;
void solve(int a[104][104]) {
    for (int i = 0; i < n; i++) {//경사로의 조건(1이라는 높이)/ㅣ이상이면 됨
        int cnt = 1;
        int j;
        for (j = 0; j < n - 1; j++) {
            if (a[i][j] == a[i][j + 1]) cnt++;
            else if (a[i][j] + 1 == a[i][j + 1] && cnt >= l) cnt = 1;//경사로 증가일 때
            else if (a[i][j] - 1 == a[i][j + 1] && cnt >= 0) cnt = -l + 1;//경사로 낮아질 떄
            else break;
        }
        if (j == n - 1 && cnt >= 0) ret++;
    }
    return;
}
int main()
{
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            b[j][i] = a[i][j];
        }
    }
    solve(a);
    solve(b);
    cout << ret << '\n';
    return 0;
}

