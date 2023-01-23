#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, m;
int a, b, marble[101][101];
vector<int> v1[101];
vector<int> v2[101];
int visited[101];
int cnt = 0;
int rcnt = 0;
void bfs(int here) {
    //정방향 bfs//
    queue<int> q;
    visited[here] = 1;
    q.push(here);

    while (q.size()) {
        int here = q.front();
        q.pop();

        for (int there : v1[here]) {
            if (visited[there]) continue;
            visited[there] = visited[here] + 1;
            q.push(there);
            cnt++;
        }
    }
}
void rbfs(int here) {
    //역방향 bfs//
    queue<int> q;
    visited[here] = 1;
    q.push(here);

    while (q.size()) {
        int here = q.front();
        q.pop();

        for (int there : v2[here]) {
            if (visited[there]) continue;
            visited[there] = visited[here] + 1;
            q.push(there);
            rcnt++;
        }
    }
}
void clear() {
    //초기화 함수
    cnt = 0;
    rcnt = 0;
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    int ans = (n + 1) / 2;
    int result = 0;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v1[a].push_back(b);
        v2[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        clear();
        bfs(i);
        rbfs(i);
        
        if (cnt >= ans || rcnt >= ans) result++;
    }
    cout << result << '\n';
    return 0;
}


