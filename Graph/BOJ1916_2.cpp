#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int INF = 987654321;
vector<pair<int, int>> bus[1001];
int d[1001];
int n, m, start, destination;
void dijkstra(int start) {
    priority_queue<pair<int, int>> pq;  // 거리, 노드 인덱스
    pq.push({ 0, start });
    d[start] = 0;

    while (pq.size()) {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (d[now] < dist) continue;

        for (int i = 0; i < bus[now].size(); i++) {
            int cost = dist + bus[now][i].second;
            int next = bus[now][i].first;
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

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        bus[a].push_back({ b, c });
    }

    cin >> start >> destination;

    for (int i = 1; i <= n; i++) {
        d[i] = INF;
    }
    dijkstra(start);
    cout << d[destination] << '\n';

    return 0;
}

