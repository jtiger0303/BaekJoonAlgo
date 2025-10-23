#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> graph(n + 1);
    vector<int> time(n + 1);
    vector<int> indegree(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> time[i];
        while (true) {
            int x;
            cin >> x;
            if (x == -1) break;
            graph[x].push_back(i); // x를 지어야 i 가능 (x -> i)
            indegree[i]++;
        }
    }
    
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    vector<int> dp = time;

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
    
    for (int i = 1; i <= n; i++) {
        cout << dp[i] << '\n';
    }
    return 0;
}

