#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
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
struct Planet {
    int idx, x, y, z;
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<Planet> v(n);

    for (int i = 0; i < n; i++) {
        v[i].idx = i;
        cin >> v[i].x >> v[i].y >> v[i].z;
    }

    vector<Edge> e;
    sort(v.begin(), v.end(), [](auto& a, auto& b) {return a.x < b.x; });
    for (int i = 1; i < n; i++) e.push_back({ abs(v[i].x - v[i - 1].x), v[i].idx, v[i - 1].idx });
    // y도
    sort(v.begin(), v.end(), [](auto& a, auto& b) {return a.y < b.y; });
    for (int i = 1; i < n; i++) e.push_back({ abs(v[i].y - v[i - 1].y), v[i].idx, v[i - 1].idx });
    // z도
    sort(v.begin(), v.end(), [](auto& a, auto& b) {return a.z < b.z; });
    for (int i = 1; i < n; i++) e.push_back({ abs(v[i].z - v[i - 1].z), v[i].idx, v[i - 1].idx });

    sort(e.begin(), e.end());
    p.resize(n);
    iota(p.begin(), p.end(), 0);
    long long ans = 0;
    for (auto& ed : e) if (find(ed.a) != find(ed.b)) {
        ans += ed.c; unite(ed.a, ed.b);
    }
    cout << ans << "\n";

}

