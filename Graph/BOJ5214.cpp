#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, k, m;
int visited[101001];
vector<vector<int>> v(101001);
queue<int> q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k >> m;

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < k; j++) {
            int station;
            cin >> station;
            v[station].push_back(i + 100000);
            v[i + 100000].push_back(station);
        }
    }

    for (int i = 1; i < 101001; i++) {
        visited[i] = 987654321;
    }

    visited[1] = 1;
    q.push(1);

    while (q.size()) {
        int front = q.front();
        q.pop();

        for (int i = 0; i < v[front].size(); i++) {
            if (visited[v[front][i]] > visited[front] + 1) {
                visited[v[front][i]] = visited[front] + 1;
                q.push(v[front][i]);
            }
        }
    }
    if (visited[n] == 987654321) cout << -1 << '\n';
    else cout << (visited[n] / 2) + 1 << '\n';
    return 0;
}

