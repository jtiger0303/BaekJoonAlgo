#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
LL n, m, idx, ret;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;//시작 위치와 끝 위치//
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (a[i].second <= idx) continue;
        if (idx < a[i].first) {
            int b = (a[i].second - a[i].first) / m + ((a[i].second - a[i].first) % m ? 1 : 0);
            ret += b;
            idx = a[i].first + b * m;
        }
        else {
            int b = (a[i].second - idx) / m + ((a[i].second - idx) % m ? 1 : 0);
            ret += b;
            idx = idx + b * m;
        }
    }
    cout << ret << '\n';
    return 0;
}

