#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int ret = 0;
void func(vector<int>& v, int cnt) {
    if (v.size() == 3) {
        cnt += v[0] * v[2];
        ret = max(ret, cnt);
        return;
    }
    for (int i = 0; i < v.size() - 2; i++) {
        vector<int> tmp=v;
        tmp.erase(tmp.begin() + i + 1);
        func(tmp, cnt + (v[i] * v[i + 2]));
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    func(v, 0);
    cout << ret << '\n';
    return 0;
}

