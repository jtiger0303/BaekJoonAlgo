#include <iostream>
#include <algorithm>
using namespace std;
int dp[1001], val[1001], n;
int main()
{
    cin >> n;
    
    //dp[i]=i번째 칸까지 올 수 있는 최소 점프 수
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
        dp[i] = 987654321;
    }
    dp[1] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= val[i]; j++) {
            if ((i + j) <= n) {
                dp[i + j] = min(dp[i] + 1, dp[i + j]);
            }
        }
    }

    if (dp[n] == 987654321) {
        cout << -1 << '\n';
    }
    else {
        cout << dp[n] << '\n';
    }
    return 0;
}

