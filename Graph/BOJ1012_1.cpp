#include <iostream>
#include <map>
using namespace std;
int n, m, k, x, y, t;
int a[51][51];
bool visited[51][51];
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (a[ny][nx] == 1 && !visited[ny][nx]) {
            dfs(ny,nx);
        }
    }
    return;
}
int main()
{   
    //connected components 구하는 문제->dfs//
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while (t--) {
        //테스트 케이스 구할 땐 초기화 중요!!//
        fill(&a[0][0], &a[0][0] + 51 * 51, 0);
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);

        cin >> m >> n >> k;
        int ret = 0;
        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            a[y][x] = 1;//배추의 위치//
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 1 && !visited[i][j]) {
                    dfs(i, j);
                    ret++;
                }
            }
        }
        cout << ret << '\n';
    }
    return 0;
}

