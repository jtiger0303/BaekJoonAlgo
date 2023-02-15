#include <iostream>
#include <vector>
#include <algorithm>
#define y aaaa
//흰 칸: 말 위로
//빨강: 반대로
//파랑: 방향 반대, 한 칸
//말이 4개 이상 종료
using namespace std;
int n, k, _map[14][14], y, x, dir;
struct Point {
    int y, x, dir;
};
vector<int> a[14][14];
vector<Point> chessStatus;
const int dy[] = { 0, 0, 0, -1, 1 };
const int dx[] = { 0, 1, -1, 0, 0 };
int _reverseDir(int dir) {
    if (dir == 1) return 2;
    if (dir == 2) return 1;
    if (dir == 3) return 4;
    if (dir == 4) return 3;
}
void _move(int y, int x, int dir, int i) {
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    if (ny < 0 || ny >= n || nx < 0 || nx >= n || _map[ny][nx] == 2) {
        //체스판을 벗어나는 경우
        chessStatus[i].dir = _reverseDir(chessStatus[i].dir);
        ny = y + dy[chessStatus[i].dir];
        nx = x + dx[chessStatus[i].dir];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n || _map[ny][nx] == 2) return;
    }
    vector<int>& v = a[y][x]; //지금 있는 기점
    vector<int>& next_v = a[ny][nx]; //가야 될 기점
    auto pos = find(v.begin(), v.end(), i); //i=몇 번째 말
    if (_map[ny][nx] == 1) reverse(pos, v.end()); //빨강색일땐 뒤집기
    for (auto it = pos; it != v.end(); it++) {
        chessStatus[*it].y = ny;
        chessStatus[*it].x = nx;
        next_v.push_back(*it);
    }
    v.erase(pos, v.end()); //원래 있던 자리에서는 삭제
    return;
}
bool isOver() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j].size() >= 4) {
                return 1;
            }
        }
    }
    return 0;
}
bool simul() {
    for (int i = 0; i < chessStatus.size(); i++) {
        //이 인덱스가 어디에 있는 건가
        int y = chessStatus[i].y;
        int x = chessStatus[i].x;
        int dir = chessStatus[i].dir;
        _move(y, x, dir, i);
        if (isOver()) return 1;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> _map[i][j];
        }
    }

    for (int i = 0; i < k; i++) {
        cin >> y >> x >> dir;
        y--;
        x--;
        a[y][x].push_back(i);
        chessStatus.push_back({ y, x, dir });
    }
    int cnt = 0;
    bool flag = 0;
    while (cnt <= 1000) {
        cnt++;
        if (simul()) {
            flag = 1;
            break;
        }
    }
    if (flag) cout << cnt << '\n';
    else cout << -1 << '\n';
    return 0;
}

