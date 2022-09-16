#include<iostream>
using namespace std;
long long dp[101] = { 0,1,1,1 };
void cal(int n) {
    for (int i = 4; i <= n; i++) {
        dp[i] = dp[i - 2] + dp[i - 3];
    }
}
int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cal(n);
        cout << dp[n] << '\n';
    }
    return 0;
}
