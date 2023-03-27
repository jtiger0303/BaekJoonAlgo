#include <iostream>
#include <queue>
#include <tuple>
#include <map>
using namespace std;
char a[1004][1004];
int r, c, sy, sx, ret, y, x;
const int INF = 987654321;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int fire_check[1004][1004], person_check[1004][1004];
queue<pair<int, int>> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;
    fill(&fire_check[0][0], &fire_check[0][0] + 1004 * 1004, INF);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];

            if (a[i][j] == 'F') {
                //불이 났다면(여러 불 가능)
                fire_check[i][j] = 1;
                q.push({ i, j });
            }
            else if (a[i][j] == 'J') {
                //지훈이의 초기 위치(한 개->sy, sx 활용)
                sy = i;
                sx = j;
            }
        }
    }
    while (q.size()) {
        tie(y, x) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
            if (fire_check[ny][nx] != INF || a[ny][nx] == '#') continue;
            fire_check[ny][nx] = fire_check[y][x] + 1;
            q.push({ ny, nx });
        }
    }

    person_check[sy][sx] = 1;
    q.push({ sy, sx });

    while (q.size()) {
        tie(y, x) = q.front();
        q.pop();

        if (y == r - 1 || y == 0 || x == c - 1 || x == 0) {
            ret = person_check[y][x];
            break;
        }
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
            if (person_check[ny][nx] || a[ny][nx] == '#') continue;
            if (fire_check[ny][nx] <= person_check[y][x] + 1) {
                //불이 확산되는 속도가 지훈이의 이동 속도보다 빠르다면
                continue;
            }
            person_check[ny][nx] = person_check[y][x] + 1;
            q.push({ ny, nx });
        
        }
    }
    if (ret != 0) cout << ret << '\n';
    else cout << "IMPOSSIBLE\n";
    return 0;
}

