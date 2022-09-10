#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001], dp[1001];
int n;

//가장 증가하는 부분 수열//
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j <= n; j++) {
            if (arr[j] < arr[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}

