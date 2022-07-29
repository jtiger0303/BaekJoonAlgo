//벨만 포드->무한히 찍어냄/사이클이 있는지 파악!!
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, s, e, m, visited[104], candi[104], a, b, c, ok;
vector<pair<int, int>> adj[104];
long long dist[104], cost[104];
const long long INF = 1LL << 60;
queue<int> q;
int main()
{
    cin >> n >> s >> e >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c; //교통수단(시작 끝 가격)
        adj[a].push_back(make_pair(b, c));
    }
    for (int i = 0; i < n; i++) {
        cin >> cost[i]; //각 도시에서 벌 수 있는 돈의 최대값

    }
    fill(dist, dist + n, -INF);
    dist[s] = cost[s];
    for (int i = 0; i < n; i++) {
        for (int here = 0; here < n; here++) {
            for (pair<int, int> there : adj[here]) {
                int _dist = there.second;
                int _there = there.first;
                if (dist[here] != -INF && dist[here] + cost[_there] - _dist > dist[_there]) {
                    //갱신이 가능하다면!!
                    dist[_there] = dist[here] + cost[_there] - _dist;
                    if (i == n - 1) q.push(here);//cycle이구나!!
                }
            }
        }
    }
    while (q.size()) {
        int here = q.front();
        q.pop();
        for (pair<int, int> there : adj[here]) {
            if (there.first == e) {
                //도착지점에 도착!
                ok = 1;
                break;
            }
            if (!visited[there.first]) {
                visited[there.first] = 1;
                q.push(there.first);
            }
        }
        if (ok) break;
    }
    if (dist[e] == -INF) puts("gg");//갱신이 안 될 때
    else if (ok) puts("Gee");
    else cout << dist[e];
}

