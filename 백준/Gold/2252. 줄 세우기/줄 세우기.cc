#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> graph[32001];
int indegree[32001]; // 각 노드의 진입 차수 저장
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

    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    while (q.size()) {
        int cur = q.front();
        q.pop();
        cout << cur << " ";

        for (int next : graph[cur]) {
            indegree[next]--;
            if (indegree[next] == 0) q.push(next);
        }
    }
    cout << '\n';
    return 0;

}

