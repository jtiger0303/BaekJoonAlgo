#include <iostream>
#include <vector>
using namespace std;
int n, m, s, e;
int num;
long dp[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
  
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        dp[i] = dp[i - 1] + num;
    }
    for (int i = 0; i < m; i++) {
        cin >> s >> e;
        cout << dp[e] - dp[s - 1] << '\n';
    }
    return 0;
}

