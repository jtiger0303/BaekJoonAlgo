#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, r, visited[100005], a, b, cnt;
vector<int> v[100005];
queue<int> q;
void bfs(int here) {
    cnt++;
    visited[here] = cnt;
    q.push(here);

    while (q.size()) {
        int here = q.front();
        q.pop();

        for (int i = 0; i < v[here].size(); i++) {
            int there = v[here][i];
            if (visited[there]) continue;
            cnt++;
            visited[there] = cnt;
            q.push(there);
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> r;

    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        sort(v[i].begin(), v[i].end(), greater<int>());
    }
    bfs(r);
    
    for (int i = 1; i <= n; i++) {
        cout << visited[i] << '\n';
    }
    return 0;
}

