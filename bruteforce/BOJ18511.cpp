#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int n, k, ans;
void pick(int num) {
    if (n < num) {
        return;
    }

    ans = max(ans, num);

    num *= 10;

    for (int i = 0; i < k; i++) {
        pick(num + v[i]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    v = vector<int>(k);

    for (int i = 0; i < k; i++) {
        cin >> v[i];
    }

    pick(0);
    cout << ans << '\n';
    return 0;
}

