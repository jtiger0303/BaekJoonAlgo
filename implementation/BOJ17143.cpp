#include <iostream>
#include <map>
#include <cstring>
using namespace std;
struct Shark {
    int x, y, s, z, dir, death;//x, y, 속력, size, 방향, 죽음
}a[104*104];
const int dx[] = { 0, 0, 0, 1, -1 };
const int dy[] = { 0, -1, 1, 0, 0 };
int _map[104][104], R, C, M, ret, temp[104][104];
int main()
{
    cin >> R >> C >> M;
    for (int i = 1; i <= M; i++) {
        cin >> a[i].y >> a[i].x >> a[i].s >> a[i].dir >> a[i].z;
        a[i].y -= 1;
        a[i].x -= 1;
        _map[a[i].y][a[i].x] = i;
    }
    for (int t = 0; t < C; t++) {//오른쪽 끝까지//
        for (int y = 0; y < R; y++) {
            if (_map[y][t]) {//상어를 먹고 size++//
                a[_map[y][t]].death = 1;
                ret += a[_map[y][t]].z;
                _map[y][t] = 0;
                break;
            }
        }
        memset(temp, 0, sizeof(temp));
        for (int i = 1; i <= M; i++) {
            if (a[i].death) continue;
            int _y = a[i].y;
            int _x = a[i].x;
            int s = a[i].s;
            int d = a[i].dir;
            int ny, nx;
            while (1) {
                ny = _y + s * dy[d];//속도*초=칸//
                nx = _x + s * dx[d];
                if (nx < C && ny < R && ny >= 0 && nx >= 0) break;
                if (d == 1 && ny < 0) {//끝까지 갈 경우에 direction을 바꿈
                    s -= _y;
                    _y = 0;
                    d = 2;//왼쪽 끝으로 갔을 땐, 오른쪽으로 방향 change//
                }
                else if (d == 2 && ny >= R) {
                    s -= R - 1 - _y;
                    _y = R - 1;
                    d = 1;//오른쪽 끝으로 갔을 땐, 왼쪽으로 방향 change//
                }
                else if (d == 3 && nx >= C) {
                    s -= C - 1 - _x;
                    _x = C - 1;
                    d = 4;//아래쪽 끝으로 갔을 땐, 위쪽으로 방향 change//
                }
                else if (d == 4 && nx < 0) {
                    s -= _x;
                    _x = 0;
                    d = 3;//위쪽 끝으로 갔을 땐, 아래쪽 방향으로 방향 change//
                }
            }
            if (temp[ny][nx]) {
                if (a[temp[ny][nx]].z < a[i].z) {
                    a[temp[ny][nx]].death = 1;
                    temp[ny][nx] = i;//temp가 있으면 비교해서 죽인다!!
                }
                else a[i].death = 1;
            }
            else temp[ny][nx] = i;
            a[i].x = nx;
            a[i].y = ny;
            a[i].dir = d;
        }
        for (int y = 0; y < R; y++) {
            for (int x = 0; x < C; x++) {
                _map[y][x] = temp[y][x];
            }
        }
    }
    cout << ret << '\n';
    return 0;
}

