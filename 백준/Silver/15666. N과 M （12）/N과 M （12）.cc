#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int n, m, arr[10], res[10];
set<vector<int>> s;
void dfs(int indx, int cnt) {
    if (cnt == m) {
        vector<int> v;
        for (int i = 0; i < m; i++) {
            v.push_back(res[i]);
        }
        s.insert(v);
        v.clear();
        return;
    }

    for (int i = indx; i < n; i++) {
        res[cnt] = arr[i];
        dfs(i, cnt + 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    dfs(0, 0);

    for (auto& b : s) {
        for (int i = 0; i < b.size(); i++) {
            cout << b[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}

