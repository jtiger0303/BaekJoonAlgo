#include <iostream>
using namespace std;
int paper[130][130], n, white, blue;
bool isSame(int y, int x, int n) {
    int num = paper[y][x];

    for (int i = y; i < y + n; i++) {
        for (int j = x; j < x + n; j++) {
            if (paper[i][j] != num) {
                return false;
            }
        }
    }
    return true;
}
void div(int y, int x, int n) {
    if (isSame(y, x, n)) {
        if (paper[y][x] == 0) { // 하얀색일 경우
            white++;
        }
        else {
            blue++;
        }
    }
    else {
        int size = n / 2;

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
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
            cin >> paper[i][j];
        }
    }

    div(0, 0, n);

    cout << white << '\n' << blue;
    return 0;
}
