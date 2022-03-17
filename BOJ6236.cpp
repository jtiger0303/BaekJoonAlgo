#include <iostream>
#include <algorithm>
using namespace std;
int n, m, a[100005], _max;
bool check(int mid) {
    int cnt = 1;
    int real_mid = mid;
    for (int i = 0; i < n; i++) {
        if (mid - a[i] >= 0) {
            mid -= a[i];
        }
        else {
            //남은 금액을 넣고 통장에서 인출//
            mid = real_mid;
            cnt++;
            if (a[i] > mid) return false;
            else mid -= a[i];
        }
    }
    return cnt <= m;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        _max = max(a[i], _max);

    }
    int lo = 1, hi = 100004, ret=0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            hi = mid - 1;
            ret = mid;
        }
        else lo = mid + 1;
    }
    cout << ret << '\n';
    return 0;
}

