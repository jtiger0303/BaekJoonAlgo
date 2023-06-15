#include <iostream>
#include <algorithm>
using namespace std;
int n, m, arr[10], visited[10], ans[10];
// 정렬 후, 이전의 값과 같다면 중복 수열!!(사전 순 출력일때만 가능)
void func(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    int ret = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && arr[i] != ret) {
            visited[i] = 1;
            ans[cnt] = arr[i];
            ret = ans[cnt];
            func(cnt + 1);
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
    func(0);


}