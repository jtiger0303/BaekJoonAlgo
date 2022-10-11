#include <iostream>
#include <algorithm>
using namespace std;
int dp[1001];
int n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    
    cin >> n;

    for (int i = 4; i <= n; i++) {
        dp[n] = min({ (dp[n - 1] + 1), (dp[n - 3] + 1), (dp[n - 4] + 1) });
    }

    if (dp[n] % 2 == 0) {
        cout << "CY" << '\n';
    }
    else {
        cout << "SK" << '\n';
    }
    return 0;
}

