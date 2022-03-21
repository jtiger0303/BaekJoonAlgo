#include <iostream>
using namespace std;
typedef long long LL;
LL a, b, mid, ret;
int main()
{
    cin >> a >> b;
    LL z = b * 100 / a;
    LL lo = 0, hi = 1e9;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if ((b + mid) * 100 / (a + mid) > z) {
            ret = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    cout << (ret ? ret : -1) << '\n';
    return 0;
}

