#include <iostream>
#include <utility> //swap함수를 쓰기 위함
using namespace std;
int n, m, k;
int r, c;
int note[42][42];
int paper[12][12];
void rotate() {
    //90도, 180도, 270도 스티커 회전
    int tmp[12][12];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            tmp[i][j] = paper[i][j];
        }
    }
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            paper[i][j] = tmp[r - 1 - j][i];
        }
    }
    swap(r, c);
}
bool pastable(int x, int y) {
    //노트북에 붙일 수 있는 가
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (note[x + i][y + j] == 1 && paper[i][j] == 1) {
                return false;
            }
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (paper[i][j] == 1) {
                note[x + i][y + j] = 1;
            }
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    while (k--) {
        cin >> r >> c;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> paper[i][j];
            }
        }
        for (int rot = 0; rot < 4; rot++) {
            //붙일 수 있는지 여부 우선 확인!!
            bool is_paste = false;
            for (int x = 0; x <= n - r; x++) {
                if (is_paste) break;
                for (int y = 0; y <= m - c; y++) {
                    if (pastable(x, y)) {
                        is_paste = true;
                        break;
                    }
                }
            }
            if (is_paste) break;
            rotate();
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cnt += note[i][j];
        }
    }
    cout << cnt << '\n';
}
