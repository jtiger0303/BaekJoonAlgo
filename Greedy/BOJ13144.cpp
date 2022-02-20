#include <iostream>
using namespace std;
long long s, e, cnt[100001], n, a[100001];
long long ret;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    while (e < n) {
        if (!cnt[a[e]]) {
            cnt[a[e]]++;
            e++;
        }
        else {
            ret += (e - s);
            cnt[a[s]]--;
            s++;
        }
    }
    ret += (long long)(e - s) * (e - s + 1) / 2;
    cout << ret << '\n';
    return 0;
}

