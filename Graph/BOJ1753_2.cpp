#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int INF = 987654321;
vector<pair<int, int>> vertex[20001];   // 최단 거리 테이블
int d[20001];
int v, e, k, start;
void dijkstra(int start) {
    priority_queue<pair<int, int>> pq;
    pq.push({ 0, start });
    d[start] = 0;

    while (pq.size()) {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (d[now] < dist) continue;

        for (int i = 0; i < vertex[now].size(); i++) {
            int cost = dist + vertex[now][i].second;
            int next = vertex[now][i].first;

            if (cost < d[next]) {
                d[next] = cost;
                pq.push({ -cost, next });
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> v >> e >> start;

    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        vertex[a].push_back({ b, c });
    }

    for (int i = 1; i <= v; i++) {
        d[i] = INF;
    }

    dijkstra(start);

    for (int i = 1; i <= v; i++) {
        if (d[i] == 987654321) cout << "INF" << '\n';
        else cout << d[i] << '\n';
    }
    return 0;
}

