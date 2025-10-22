#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int t, n, k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    
    while (t--) {
        cin >> n >> k;
        vector<int> time(n + 1);
        vector<vector<int>> graph(n + 1);
        vector<int> indegree(n + 1);

        for (int i = 1; i <= n; i++) {
            cin >> time[i];
        }

        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
            indegree[y]++;
        }

        int target;
        cin >> target;

        vector<int> dp = time;
        queue<int> q;

        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        while (q.size()) {
            int cur = q.front();
            q.pop();

            for (int next : graph[cur]) {
                indegree[next]--;
                if (dp[next] < dp[cur] + time[next]) {
                    dp[next] = dp[cur] + time[next];
                }
                if (indegree[next] == 0) q.push(next);
            }
        }
        cout << dp[target] << "\n";
    }
    return 0;
}

