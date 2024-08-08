#include <iostream>
using namespace std;
int n, board[2200][2200], sum1, sum2, sum3;
bool isSame(int y, int x, int n) {
    int num = board[y][x];

    for (int i = y; i < y + n; i++) {
        for (int j = x; j < x + n; j++) {
            if (num != board[i][j]) {
                return false;
            }
        }
    }
    return true;
}
void div(int y, int x, int n) {
    // 종이 자르기
    if (isSame(y, x, n)) {  // 종이가 모두 같은 수로 구성되어 있을 때
        if (board[y][x] == -1) {
            sum1++;
        }
        else if (board[y][x] == 0) {
            sum2++;
        }
        else if (board[y][x] == 1) {
            sum3++;
        }
    }
    else {
        int size = n / 3;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                div(size * i + y, size * j + x, size);
            }
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
            cin >> board[i][j];
        }
    }
    div(0, 0, n);
    cout << sum1 << '\n' << sum2 << '\n' << sum3;
    return 0;
}

