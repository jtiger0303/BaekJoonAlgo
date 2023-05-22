#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
int n, k, l, t, y, x, ret, idx, dir = 1;
int a[104][104], visited[104][104];
char c;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
deque<pair<int, int>> dq;
vector<pair<int, int>> _time;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int time = 0;
    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        cin >> y >> x;
        a[--y][--x] = 1;
    }
    cin >> l;
    for (int i = 0; i < l; i++) {
        cin >> t >> c;
        if (c == 'D') {
            _time.push_back({ t, 1 });
        }
        else {
            _time.push_back({ t, 3 });
        }
    }
    dq.push_back({ 0, 0 }); //맨 위 맨 좌측에 위치

    while (dq.size()) {
        time++;
        tie(y, x) = dq.front();
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) break;
        if (!a[ny][nx]) {
            //사과가 없다면 몸 길이를 줄여서 꼬리가 위치한 칸을 비워준다. 즉 몸길이는 변하지 않는다
            visited[dq.back().first][dq.back().second] = 0;
            dq.pop_back();
        }
        else {
            //사과가 있다면 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다
            a[ny][nx] = 0;
        }
        visited[ny][nx] = 1;
        dq.push_front({ ny, nx }); //머리를 다음 칸에 위치
        if (time == _time[idx].first) {
            dir = (dir + _time[idx].second) % 4;
            idx++;
        }

    }
    cout << time << '\n';
    return 0;

}

