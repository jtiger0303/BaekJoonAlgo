#include <iostream>
#include <cstring>
using namespace std;
int n, m, c, y, x, a[51][51], dp[51][51][51][51];
const int mod = 1000007;
int go(int y, int x, int cnt, int prev) {
    if (y > n || x > m) return 0;
    if (y == n && x == m) {
        if (cnt == 0 && a[y][x] == 0) return 1; //다 구할 때
        if (cnt == 1 && a[y][x] > prev) return 1; // 방문해도 좋을 때
        return 0;
    }
    int& ret = dp[y][x][cnt][prev];
    if (ret != -1) return ret;
    ret = 0;
    if (a[y][x] == 0) {
        //모든 곳이든지 갈 수 있을 때
        ret = (go(y + 1, x, cnt, prev) + go(y, x + 1, cnt, prev)) % mod;
        //위로 가는 것과 옆으로 가는 것
    }
    else if (a[y][x] > prev) {
        //갈 수 있는 것
        ret = (go(y + 1, x, cnt - 1, a[y][x]) + go(y, x + 1, cnt - 1, a[y][x])) % mod;
    }
    return ret;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n >> m >> c;
    for (int i = 1; i <= c; i++) {
        cin >> y >> x;
        a[y][x] = i;
    }
    for (int i = 0; i <= c; i++) {
        cout << go(1, 1, i, 0) << " ";
    }
    return 0;
}
