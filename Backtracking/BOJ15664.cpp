#include <iostream>
#include <algorithm>
using namespace std;
int n, m, arr[10], res[10], visited[10];
void func(int idx, int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            cout << res[i] << ' ';
        }
        cout << '\n';
    }
    int ret = 0;
    for (int i = idx; i < n; i++) {
        if (!visited[i] && ret != arr[i]) {
            visited[i] = 1;
            res[cnt] = arr[i];
            ret = arr[i];
            func(i, cnt + 1);
            visited[i] = 0;
        }
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
    func(0, 0);
}

