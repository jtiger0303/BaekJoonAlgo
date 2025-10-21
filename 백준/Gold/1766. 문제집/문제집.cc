#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> graph[32001];
int indegree[32001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) pq.push(i);
    }

    while (pq.size()) {
        int cur = pq.top();
        pq.pop();

        cout << cur << " ";

        for (int next : graph[cur]) {
            indegree[next]--;
            if (indegree[next] == 0) pq.push(next);
        }
    }
    return 0;
}

