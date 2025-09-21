#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge {
    int c, a, b;
    bool operator<(const Edge& other) {
        return c < other.c;
    }
};
vector<int> p;
int find(int x) {
    while (x != p[x]) { 
        x = p[x] = p[p[x]];
    }
    return x;
}
void unite(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return;
    p[y] = x;
}
int n, m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    vector<Edge> e(m);

    for (int i = 0; i < m; i++) {
        cin >> e[i].a >> e[i].b >> e[i].c;
    }

    sort(e.begin(), e.end());
    p.resize(n + 1);

    long long ans = 0;
    int maxCost = 0;
    for (int i = 1; i <= n; i++) p[i] = i;

    for (int i = 0; i < m; i++) {
        if (find(e[i].a) != find(e[i].b)) {
            maxCost = max(maxCost, e[i].c);
            ans += e[i].c;
            unite(e[i].a, e[i].b);
        }
    }
    cout << ans - maxCost << '\n';
    return 0;
}
