#include <iostream>
#include <queue>
#include <map>
#include <tuple>
using namespace std;
const int INF = 987654321;
int r, c, water_check[51][51], hedge_check[51][51], sy, sx, y, x, ret;
char a[51][51];
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
queue<pair<int, int>> q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;
    fill(&water_check[0][0], &water_check[0][0] + 51 * 51, INF);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];

            if (a[i][j] == '*') {
                //물이 
                water_check[i][j] = 1;
                q.push({ i, j });
            }

            else if (a[i][j] == 'S') {
                //고슴동치
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
            if (water_check[ny][nx] != INF || a[ny][nx] == 'X') continue;
            if (a[ny][nx] == 'D') continue;

            water_check[ny][nx] = water_check[y][x] + 1;
            q.push({ ny, nx });
        }
    }
    hedge_check[sy][sx] = 1;
    q.push({ sy, sx });

    while (q.size()) {
        tie(y, x) = q.front();
        q.pop();

        if (a[y][x] == 'D') {
            ret = hedge_check[y][x]-1;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
            if (hedge_check[ny][nx] || a[ny][nx] == 'X') continue;
            if (water_check[ny][nx] <= hedge_check[y][x] + 1) continue;
            hedge_check[ny][nx] = hedge_check[y][x] + 1;
            q.push({ ny, nx });
        }
    }
    if (ret != 0) cout << ret << '\n';
    else cout << "KAKTUS" << '\n';
    return 0;
}

