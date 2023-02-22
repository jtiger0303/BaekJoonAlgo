#include <iostream>
using namespace std;
typedef long long LL;
LL n, a[104], dp[104][21];
LL go(int idx, int sum) {
    //idx: 현재 위치, sum: 이전까지 total
    if (sum < 0 || sum>20) return 0;
    LL& ret = dp[idx][sum];
    if (ret) return ret;
    if (idx == n - 2) {
        if (sum == a[n - 1]) return 1;
        return 0;
    }
    ret += go(idx + 1, sum + a[idx + 1]); //더할 것인가
    ret += go(idx + 1, sum - a[idx + 1]); //뺼 것인가
    return ret;
}
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << go(0, a[0]) << '\n';
    return 0;
}

