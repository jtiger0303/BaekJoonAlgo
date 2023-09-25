#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, l, r, x, a[15], visit[15], ret;
vector<int> v;
void func(int idx, int cnt, int maxi, int mini, int sum) {
    if (cnt==n) {
        if (maxi - mini >= x) {
            if (sum >= l && sum <= r) {
                ret++;
            }
        }
        return;
    }
    //i번째 문자를 포함한 것/아닌 것
    for (int i = idx; i < n; i++) {
        func(i + 1, cnt + 1, max(v[i], maxi), min(mini, v[i]), sum + v[i]);
        func(i + 1, cnt+1, maxi, mini, sum);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l >> r >> x;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        v.push_back(a[i]);
    }
    func(0, 0, 0, 987654321, 0);
    cout << ret << '\n';
    return 0;

}

