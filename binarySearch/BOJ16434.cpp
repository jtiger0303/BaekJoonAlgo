#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, attack, t[140005], a[140005], h[140005];
bool check(ll mid) {
    ll init_hp = mid;
    ll init_attack = attack;//attack은 증가할 수 있다//
    for (int i = 0; i < n; i++) {
        if (t[i] == 2) {
            mid = min(init_hp, mid + h[i]);
            init_attack += a[i];
        }
        else {
            ll div = h[i] / init_attack + (h[i] % init_attack ? 1 : 0); //몇 번을 때리나?//
            ll attack_cnt = div - 1;
            mid -= attack_cnt *a[i];
        }
        if (mid <= 0) return false; //죽은 상태
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> attack;
    ll init_lo = 1;
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> a[i] >> h[i];
    }
    ll lo = 1, hi = 1e18 + 4, ret;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (check(mid)) {
            hi = mid - 1;
            ret = mid;
        }
        else lo = mid + 1;
    }
    cout << ret << '\n';
    return 0;
}
