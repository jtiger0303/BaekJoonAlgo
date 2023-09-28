#include <iostream>
#include <algorithm>
using namespace std;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, m, k, board[12][12], visited[12][12], sum;
int ret = -987654321;
void func(int sum, int cnt) {
    if (cnt == k) {
        ret = max(ret, sum);
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j]) continue;
            bool check = true;
            for (int k = 0; k < 4; k++) {
                int ny = i + dy[k];
                int nx = j + dx[k];

                if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                if (visited[ny][nx]) check = false;
            }
            if (check) {
                visited[i][j] = 1;
                func(sum + board[i][j], cnt + 1);
                visited[i][j] = 0;
            }
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    func(0, 0);
    cout << ret << '\n';
    return 0;
}

