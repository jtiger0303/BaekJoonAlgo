#include <iostream>
#include <cstring>
using namespace std;
int n, visited[100002], student[100002], t, cnt;
int done[100002];
void dfs(int here) {
    visited[here] = 1;

    int there = student[here];
    if (!visited[there]) {
        dfs(there);
    }
    else if (!done[there]) {
        //방문했지만 사이클이 완성되지 않았을 경우
        for (int i = there; i != here; i = student[i]) {
            cnt++;
        }
        cnt++; //자기 자신 추가
    }
    done[here] = 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while (t--) {
        cnt = 0;
        memset(visited, 0, sizeof(visited));
        memset(done, 0, sizeof(done));

        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> student[i];
        }

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        cout << n - cnt << '\n';


    }
    return 0;
}
