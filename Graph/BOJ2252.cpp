#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
int visited[32001];
vector<int> v[32001];
queue<int> q;
void dfs(int x) {
    visited[x] = 1;
    for (auto g : v[x]) {
        if (!visited[g]) dfs(g);
    }
    q.push(x);
 }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    while (q.size()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
    
}
