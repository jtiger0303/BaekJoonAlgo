#include <iostream>
using namespace std;
long long dp[101][101];
int n, m, k;
//dp[n][m]=n개의 "a"와 m개의 "z"로 이루어진 문자열의 개수 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;

    for (int i = 1; i <= 100; i++) {
        dp[i][0] = dp[0][i] = 1;
    }

    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            if (dp[i][j] > 1000000000) dp[i][j] = 1000000000;
        }
    }

    int a_cnt = n;
    int z_cnt = m;

    if (dp[n][m] < k) {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 0; i < n + m; i++) {
        int a_start = dp[a_cnt - 1][z_cnt];
        int z_start = dp[a_cnt][z_cnt - 1];

        if (a_cnt == 0) {
            cout << 'z';
            z_cnt--;
            continue;
        }

        else if (z_cnt == 0) {
            cout << 'a';
            a_cnt--;
            continue;
        }

        if (k <= a_start) {
            cout << 'a';
            a_cnt--;
        }
        else {
            k = k - a_start;
            cout << 'z';
            z_cnt--;
        }
    }
    cout << '\n';
    return 0;
}

