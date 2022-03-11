#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, m, a[300004], ret = 1e18;
bool check(ll mid) {
    ll num = 0;
    for (int i = 0; i < m; i++) {
        num += a[i] / mid;
        if (a[i] % mid) num++;
    }
    return n >= num;
}
int main()
{   //최소, 최대 결정문제//
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    ll lo = 1, hi = 0, mid;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        hi = max(hi, a[i]);
    }
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (check(mid)) {
            ret = min(ret, mid);//최소를 구할 떄//
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    cout << ret << '\n';
    return 0;
}

