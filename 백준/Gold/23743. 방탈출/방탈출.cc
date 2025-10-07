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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<Edge> e;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        e.push_back({ c, a, b });
    }

    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        e.push_back({ t, 0, i });
    }

    sort(e.begin(), e.end());
    p.resize(n + 1);
    for (int i = 0; i <= n; i++) {
        p[i] = i;
    }

    long long ans = 0;
    int connected = 0;

    for (int i = 0; i < e.size(); i++) {
        if (find(e[i].a) != find(e[i].b)) {
            ans += e[i].c;
            unite(e[i].a, e[i].b);
            connected++;
        }
        if (connected == n) break;
    }
    cout << ans << '\n';
    return 0;
}

