#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, k, A[14][14], yangbun[14][14], ret;
vector<int> _map[14][14];
const int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
void springSummer() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (_map[i][j].size() == 0) continue;
            int die_tree = 0;
            //죽은 나무가 생기기 때문에 temp 활용
            vector<int> temp;
            sort(_map[i][j].begin(), _map[i][j].end());
            for (int tree : _map[i][j]) {
                if (yangbun[i][j] >= tree) {
                    yangbun[i][j] -= tree;
                    temp.push_back(tree + 1);
                }
                else {
                    //그러지 않다면 죽는다.
                    die_tree += tree / 2;
                }
            }
            _map[i][j].clear();
            _map[i][j] = temp;
            yangbun[i][j] += die_tree;
        }
    }
}
void fall() {
    //번식
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (_map[i][j].size() == 0) continue;
            for (int tree : _map[i][j]) {
                if (tree % 5 == 0) {
                    for (int d = 0; d < 8; d++) {
                        int ny = i + dy[d];
                        int nx = j + dx[d];
                        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                        _map[ny][nx].push_back(1);
                    }
                }
            }
        }
    }
}
void winter() {
    //양분 추기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            yangbun[i][j] += A[i][j];
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
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
            yangbun[i][j] = 5;
        }
    }

    for (int i = 0; i < m; i++) {
        int _a, _b, _c;
        cin >> _a >> _b >> _c;
        _a--; //나무의 위치
        _b--;
        _map[_a][_b].push_back(_c);

    }
    for (int i = 0; i < k; i++) {
        springSummer();
        fall();
        winter();
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ret += _map[i][j].size();
        }
    }
    cout << ret << '\n';
    return 0;
}

