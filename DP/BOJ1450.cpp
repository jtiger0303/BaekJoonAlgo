#include <iostream>
#include <vector>
#include <algorithm>
typedef long long LL;
using namespace std;
LL n, c, a[31], ret;
vector<int> v, v2;
void go(int here, int _n, vector<int>& v, int sum) {
    if (sum > c) return;
    if (here > _n) {
        v.push_back(sum);
        return;
    }
    go(here + 1, _n, v, sum + a[here]); //물건을 넣을 것인가
    go(here + 1, _n, v, sum); //안 넣을 것인가
    return;
}
int main()
{
    //vector를 2개로 나눠서 조합!!
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    go(0, n / 2 - 1, v, 0);
    go(n / 2, n - 1, v2, 0);
    sort(v.begin(), v.end());
    sort(v2.begin(), v2.end());
    for (int b : v) {
        if (c - b >= 0) ret += ((int)(upper_bound(v2.begin(), v2.end(), c - b) - v2.begin()));

    }
    cout << ret << '\n';
    return 0;
}

