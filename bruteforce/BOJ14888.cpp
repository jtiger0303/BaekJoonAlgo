#include <iostream>
#include <algorithm>
using namespace std;
int n;
int a[12], b[4];
int p, minu, mult, divi;
int ret = -1000000001;
int ret2 = 1000000001;
void go(int index, int cur, int plus, int minus, int mul, int div) {
    if (index == n - 1) {
        ret = max(cur, ret);
        ret2 = min(ret2, cur);
        return;
    }
    if (plus) go(index + 1, cur + a[index + 1], plus - 1, minus, mul, div);
    if (minus) go(index + 1, cur - a[index + 1], plus, minus - 1, mul, div);
    if (mul) go(index + 1, cur * a[index + 1], plus, minus, mul - 1, div);
    if (div) go(index + 1, cur / a[index + 1], plus, minus, mul, div - 1);
    return;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> p >> minu >> mult >> divi;
    go(0, a[0], p, minu, mult, divi);
    cout << ret << '\n' << ret2 << '\n';
    return 0;
}
