#include <iostream>
using namespace std;
int n, m, lo, hi, ret, a[100004], psum;
bool check(int mid) {
    for (int i = 0; i < n; i++) {
        if (a[i] > mid) {
            return false;//a[i]는 기타레슨 강의의 길이
        }
    }
    int temp = mid;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (mid - a[i] < 0) {
            mid = temp;
            cnt++;
        }
        mid -= a[i];
    }
    if (mid != temp) cnt++;
    return cnt <= m;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        psum += a[i];
    }
    lo = 0;
    hi = psum;

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

