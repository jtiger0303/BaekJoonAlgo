#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<pair<int, int>> v[10005];
int n, visited[10005], maxi, maxNode;
void dfs(int here, int cnt) {
    visited[here] = 1;
    if (maxi < cnt) {
        maxi = cnt;
        maxNode = here;
    }
    for (int i = 0; i < v[here].size(); i++) {
        int there = v[here][i].first;
        if (visited[there]) continue;
        dfs(there, cnt + v[here][i].second);
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({ b, c });
        v[b].push_back({ a, c });
    }
    dfs(1, 0);
    memset(visited, 0, sizeof(visited));
    maxi = -1;
    dfs(maxNode, 0);
    cout << maxi << '\n';
    return 0;
}
