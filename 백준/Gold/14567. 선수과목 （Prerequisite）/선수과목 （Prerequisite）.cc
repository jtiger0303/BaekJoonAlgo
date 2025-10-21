#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    vector<int> indegree(n + 1, 0); // 진입 차수
    vector<int> semester(n + 1, 1); // 각 과목 최소 이수 학기 (초기값 1)

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b; // a가 b의 선수 과목
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

        for (int next : graph[cur]) {
            indegree[next]--;
            // next 과목은 cur보다 반드시 한 학기 이후에 가능
            if (semester[next] < semester[cur] + 1) {
                semester[next] = semester[cur] + 1;
            }
            if (indegree[next] == 0) q.push(next);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << semester[i] << ' ';
    }
    cout << '\n';
    return 0;

}

