#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m, visited[20002], a, b, idx, cnt;
vector<int> v[20002];
queue<int> q;
void bfs(int here) {
    visited[here] = 1;
    q.push(here);

    while (q.size()) {
        int here = q.front();
        q.pop();

        for (int there : v[here]) {
            if (visited[there]) continue;
            visited[there] = visited[here] + 1;
            q.push(there);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    int max = -987654321;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfs(1);

    for (int i = 2; i <= n; i++) {
        if (visited[i] > max) {
            max = visited[i];
            idx = i;
            cnt=1;
        }
        else if (visited[i] == max) {
            cnt++;
        }
    }
    cout << idx << ' ' << max - 1 << ' ' << cnt;
    return 0;
}

