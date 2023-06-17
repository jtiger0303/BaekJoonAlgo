#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
int n, m, arr[8], res[8];
set<vector<int>> ans; //중복 허용 X를 위한 set
void dfs(int cnt) {
    if (cnt == m) {
        vector<int> v;
        for (int i = 0; i < m; i++) {
            v.push_back(res[i]);
        }
        ans.insert(v);
        v.clear();
        return;
    }
    for (int i = 0; i < n; i++) {
        res[cnt] = arr[i];
        dfs(cnt + 1);
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
    dfs(0);

    for (auto& b : ans) {
        for (int i = 0; i < b.size(); i++) {
            cout << b[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}

