#include <iostream>
#include <algorithm>
using namespace std;
int n, dp[101], cost[101], happy[101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> cost[i];
    for (int i = 0; i < n; i++) cin >> happy[i];
    for (int i = 0; i < n; i++) {
        for (int j = 100; j > cost[i]; j--) {
            dp[j] = max(dp[j], dp[j - cost[i]] + happy[i]);
        }
    }
    cout << dp[100] << '\n'; //어떤 인덱스에서의 최대치//
    return 0;
}

