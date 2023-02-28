#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int k, n, dir;
string gear[4];
int isRotate[4];
void init() {
    memset(isRotate, 0, sizeof(isRotate));
}
void move(int idx, int clock) {
    if (clock == 1) {
        //시계방향
        gear[idx] = gear[idx].substr(7) + gear[idx].substr(0, 7); // ex:10101111->11010111

    }
    else if (clock == -1) {
        //반시계 방향
        gear[idx] = gear[idx].substr(1, 7) + gear[idx].substr(0, 1);
        //ex: 10101111->0101111
    }
}
void left_check(int idx, int clock) {
    if (idx <= 0) return;
    if (gear[idx][6] != gear[idx - 1][2]) {
        isRotate[idx - 1] = clock * -1; //방향 전환
        left_check(idx - 1, clock * -1);
    }
}
void right_check(int idx, int clock) {
    if (idx >= 3) return;
    if (gear[idx][2] != gear[idx + 1][6]) {
        isRotate[idx + 1] = clock * -1;
        right_check(idx + 1, clock * -1);
    }
}
void check(int idx, int clock) {
    isRotate[idx] = clock;
    left_check(idx, clock);
    right_check(idx, clock);

    for (int i = 0; i < 4; i++) {
        move(i, isRotate[i]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ans = 0;
    for (int i = 0; i < 4; i++) {
        cin >> gear[i];
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> n >> dir;
        init();
        check(n - 1, dir);
    }

    int mul = 1;
    for (int i = 0; i < 4; i++) {
        ans += (gear[i][0] - 48) * mul;
        mul *= 2;
    }
    cout << ans << '\n';
    return 0;
}

