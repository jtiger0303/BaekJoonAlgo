#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, r, visited[100005], cnt;
vector<int> v[100005];
void dfs(int here) {
    cnt++;
    visited[here] = cnt;

    for (int i = 0; i < v[here].size(); i++) {
        int there = v[here][i];
        if (visited[there]) continue;
        dfs(there);
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
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        sort(v[i].begin(), v[i].end(), greater<int>());
    }
    dfs(r);

    for (int i = 1; i <= n; i++) {
        cout << visited[i] << '\n';
    }
    return 0;
}

