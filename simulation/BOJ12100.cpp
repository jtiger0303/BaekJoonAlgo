#include <iostream>
#include <algorithm>
using namespace std;
int n;
int board1[21][21];
int board2[21][21];

void rotate() {
    int tmp[21][21];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmp[i][j] = board2[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board2[i][j] = tmp[n - 1 - j][i];
        }
    }
}
void tilt(int dir) {
    //기울이는 함수: 1->90도...
    while (dir--) rotate();
    for (int i = 0; i < n; i++) {
        int tilted[21] = {};
        int idx = 0;
        for (int j = 0; j < n; j++) {
            if (board2[i][j] == 0) continue;
            if (tilted[idx] == 0) {
                //빈칸이라면 board2 배치
                tilted[idx] = board2[i][j];
            }
            else if (tilted[idx] == board2[i][j]) {
                tilted[idx++] *= 2;
            }
            else {
                tilted[++idx] = board2[i][j];
            }
        }
        for (int j = 0; j < n; j++) {
            board2[i][j] = tilted[j];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board1[i][j];
        }
    }
    int mx = 0; //5번 이동시켜서 얻을 수 있는  가장 큰 블록
    for (int tmp = 0; tmp < 1024; tmp++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                board2[i][j] = board1[i][j];
            }
        }
        int brute = tmp;
        for (int i = 0; i < 5; i++) { //검사 문제 참고!!
            int dir = brute % 4;
            brute /= 4;
            tilt(dir);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mx = max(mx, board2[i][j]);
            }
        }
    }
    cout << mx << '\n';
    return 0;
}

