#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, parent[1010], sum;
vector<pair<int, pair<int, int>>> v;
int find(int x) {
    if (parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}
void uni(int x, int y) {
    x = find(x);
    y = find(y);
    parent[y] = x;
}
bool isSameParent(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return true;
    else return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        v.push_back({ cost, {from, to} });
    }
    sort(v.begin(), v.end()); // 오름차순으로 정렬

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < v.size(); i++) {
        if (!isSameParent(v[i].second.first, v[i].second.second)) {
            uni(v[i].second.first, v[i].second.second);
            sum += v[i].first;
        }
    }

    cout << sum << '\n';
    return 0;

}

