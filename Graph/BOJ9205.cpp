#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n;
vector<int> festival[102];
int visited[102];

int distance(pair<int, int> p1, pair<int, int> p2) { //거리 계산//
    return abs(p2.first - p1.first) + abs(p2.second - p1.second);
}
void dfs(int x) {
    visited[x] = 1;
    for (int i = 0; i < festival[x].size(); i++) {
        int next = festival[x][i];
        if (!visited[next]) {
            dfs(next);
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < 102; j++) {
            festival[j].clear();
        }
        memset(visited, 0, sizeof(visited));
        cin >> n;
        vector<pair<int, int>> v;

        for (int j = 0; j < n + 2; j++) {
            int y, x;
            cin >> y >> x;
            v.push_back(make_pair(y, x));
        }
        for (int j = 0; j < n + 2; j++) {
            for (int k = j + 1; k < n + 2; k++) {
                if (distance(v[j], v[k]) <= 50 * 20) {
                    //거리에 있으면 그래프 추가//
                    festival[j].push_back(k);
                    festival[k].push_back(j);
                }
            }
        }
        dfs(0);
        if (visited[n + 1]) cout << "happy" << '\n';
        else cout << "sad" << '\n';
    }
    return 0;
}

