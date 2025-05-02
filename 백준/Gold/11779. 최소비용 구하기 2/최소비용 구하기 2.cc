#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 987654321;
vector<pair<int, int>> bus[1001]; // 최단거리 테이믈
vector<int> ret;
int d[1001], route[1001], n, m;
void dijkstra(int start) {
    priority_queue<pair<int, int>> pq;  // 거리, 노드 인덱스
    pq.push({ 0, start });
    d[start] = 0;

    while (pq.size()) {
        int dist = -pq.top().first; // 현재 노드까지의 비용
        int now = pq.top().second;  // 현재 노드
        pq.pop();

        if (d[now] < dist) continue;

        for (int i = 0; i < bus[now].size(); i++) {
            int cost = dist + bus[now][i].second;   //거쳐서 가는 노드의 비용을 계산
            int next = bus[now][i].first;

            if (cost < d[next]) {
                route[next] = now;
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
    int start, destination;
    cin >> start >> destination;

    for (int i = 1; i <= n; i++) {
        d[i] = INF;
    }

    dijkstra(start);

    route[start] = 0;
    int indx = destination;

    while (true) {
        if (route[indx] == 0) {
            ret.push_back(indx);
            break;
        }
        ret.push_back(indx);
        indx = route[indx];
    }
    reverse(ret.begin(), ret.end());

    cout << d[destination] << '\n' << ret.size() << '\n';
    for (auto ans : ret) {
        cout << ans << ' ';
    }
    return 0;
}

