#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, visited[30][30], a[30][30], cnt;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
string str;
vector<int> ans;
int dfs(int y, int x, int cnt) {
    visited[y][x] = cnt;
    int ret = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if (a[ny][nx] == 1 && !visited[ny][nx]) {
            ret += dfs(ny, nx, cnt);
        }

    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < n; j++) {
            a[i][j] = str[j]-48;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 1 && !visited[i][j]) {
                cnt++;
                ans.push_back(dfs(i, j, cnt));
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << cnt << '\n';

    for (int i : ans) {
        cout << i << '\n';
    }
    return 0;


}

