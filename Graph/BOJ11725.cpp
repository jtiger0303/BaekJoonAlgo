#include <iostream>
#include <vector>
using namespace std;
int visited[100004], parent[100004];
int n, a, b;
vector<int> v[100004];
void dfs(int here) {
    visited[here] = 1;
    for (int there : v[here]) {
        if (!visited[there]) {
            parent[there] = here;
            dfs(there);
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    for (int i = 2; i <= n; i++) {
        cout << parent[i] << '\n';
    }
    return 0;
}

