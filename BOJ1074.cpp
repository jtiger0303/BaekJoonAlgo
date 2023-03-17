#include <iostream>
using namespace std;
typedef long long ll;
int n, r, c;
ll ans = 0;
void func(int cur, int x, int y) {
    if (cur == 1) return;
    ll cnt = 0;
    for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 2; b++) {
            if (x + a * (cur / 2) <= r && r < x + (a + 1) * (cur / 2) && y + b * (cur / 2) <= c && c < y + (b + 1) * (cur / 2)) {
                ans += cnt;
                func(cur / 2, x + a * (cur / 2), y + b * (cur / 2));
                return;
            }
            cnt += ((cur / 2) * (cur / 2));
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> r >> c;

    int v = 1;
    for (int i = 0; i < n; i++) {
        v *= 2;
    }
    func(v, 0, 0);
    cout << ans << '\n';
    return 0;
}

