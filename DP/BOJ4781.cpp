#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
int dp[10001];
int c, p;
int main()
{
    //무한->왼쪽에서 오른쪽으로 dp 누적!!
    while (1) {
        int n, m1, m2;
        scanf("%d %d.%d", &n, &m1, &m2);
        if (n == 0) break;
        int cost = m1 * 100 + m2;
        fill(dp, dp + 10001, 0);
        for (int i = 0; i < n; i++) {
            scanf("%d %d.%d", &c, &m1, &m2);
            p = m1 * 100 + m2;

            for (int j = p; j <= cost; j++) {
                dp[j] = max(dp[j], dp[j - p] + c);
            }
        }
        printf("%d\n", dp[cost]);
    }
    return 0;
}

