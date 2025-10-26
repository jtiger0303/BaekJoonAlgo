#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;
typedef long long LL;
typedef tuple<LL, int, int> T; // (누적요금, 도시번호, 잔돈 modK)
int n, m, k, s, t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k >> s >> t;

    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({ v, w });
    }

    // dist[v][r]: v도시에 잔돈 r로 도달하는 최소 지불 요금
    vector<vector<LL>> dist(n + 1, vector<LL>(k, LLONG_MAX));
    priority_queue<T, vector<T>, greater<T>> pq;
    dist[s][0] = 0;
    pq.push({ 0, s, 0 });

    while (pq.size()) {
        LL cost;
        int cur, rem;
        tie(cost, cur, rem) = pq.top();
        pq.pop();

        if (dist[cur][rem] < cost) continue;

        for (auto& next : graph[cur]) {
            LL ncost = cost + next.second; // 이용료의 합
            int nrem = ncost % k;
            // 무조건 k의 배수일 필요 X -> 총 이용료의 합이 K의 배수일 떄만 확인

            if (dist[next.first][nrem] > ncost) {
                dist[next.first][nrem] = ncost;
                pq.push({ ncost, next.first, nrem});
            }
        }
    }

    if (dist[t][0] == LLONG_MAX) {
        cout << "IMPOSSIBLE\n";
    }
    else cout << dist[t][0] << '\n';
}

