#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m, x, y, V;
int visited[1001];
vector<int> v[10001];
queue<int> q;
vector<int> res_bfs;
vector<int> res_dfs;
void dfs(int here) {
    visited[here] = 1;
    res_dfs.push_back(here);

    for (int i = 0; i < v[here].size(); i++) {
        if (!visited[v[here][i]]) {
            dfs(v[here][i]);
        }
    }
    return;
}
void bfs(int here) {
    visited[here] = 1;
    q.push(here);

    while (q.size()) {
        int here = q.front();
        q.pop();
        res_bfs.push_back(here);

        for (int i = 0; i < v[here].size(); i++) {
            if (visited[v[here][i]]) continue;
            visited[v[here][i]] = visited[here] + 1;
            q.push(v[here][i]);
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> V;

    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        sort(v[i].begin(), v[i].end());
    }

    dfs(V);
    memset(visited, 0, sizeof(visited));
    bfs(V);

    for (auto ret : res_dfs) {
        cout << ret << ' ';
    }
    cout << '\n';

    for (auto ret : res_bfs) {
        cout << ret << ' ';
    }
}
