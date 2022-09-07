#include <iostream>
#include <vector>
using namespace std;
int n, m;
int dp[41], vip[41];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> vip[i];
    }
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= 40; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    if (m > 0) {//VIP가 있는 경우
        vector<int> interval;
        interval.push_back(vip[0] - 1);//첫번째 VIP와 첫번째 좌석의 차이
        interval.push_back(n - vip[m - 1]);//마지막 VIP와 마지막 좌석의 차이

        for (int i = 0; i < m - 1; i++) {
            interval.push_back(vip[i + 1] - vip[i] - 1);//첫번째 VIP와 두번째 VIP 사이의 차이

        }
        int res = 1;
        for (auto i : interval) {
            res *= dp[i];
        }
        cout << res << '\n';
    }
    else {
        cout << dp[n] << '\n';
    }
    return 0;
}