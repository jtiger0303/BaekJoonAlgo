#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, a, b, ret;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;
int main()
{   //최소를 뺴버리고 최대로!!//
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({ a, b });
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        ret += v[i].second;
        pq.push(v[i].second);
        if (pq.size() > v[i].first) {
            ret -= pq.top();
            pq.pop();
        }
    }
    cout << ret << '\n';
    return 0;
}

