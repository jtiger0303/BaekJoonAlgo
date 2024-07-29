#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
queue<pair<int, int>> q;
int n, m, visited[102], a, b, ret;
int mini = 987654321;
vector<vector<int>> v;
vector<int> result;
int bfs(int here) {
    visited[here] = 1;
    int sum = 0;
    q.push({here, 0});

    while (q.size()) {
        int here = q.front().first;
        int dist = q.front().second;
        sum += dist;
        q.pop();

        for (int i = 0; i < v[here].size(); i++) {
            int next = v[here][i];
            if (visited[next]) continue;
            visited[next] = visited[here] + 1;
            q.push({next, dist + 1});
        }
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    v.resize(n + 1);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 1; i < v.size(); i++) {
        memset(visited, 0, sizeof(visited));
        result.push_back(bfs(i));
    }

    for (int i = 0; i < result.size(); i++) {
        mini = min(mini, result[i]);
    }

    for (int i = 0; i < result.size(); i++) {
        if (mini == result[i]) {
            ret = i;
            break;
        }
    }
    cout << ret + 1 << '\n';
    return 0;
}
