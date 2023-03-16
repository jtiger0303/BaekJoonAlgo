#include <iostream>
using namespace std;
int n, m, x, y, k;
int map[21][21];
int order[1001];
int dice[6]; //{위, 아래, 동, 서, 남, 북}
int judge(int dir) {
    //갈 수 있는 지 판단
    if (dir == 1) {
        if (y == m - 1) return 0;
    }
    else if (dir == 2) {
        if (y == 0) return 0;
    }
    else if (dir == 3) {
        if (x == 0) return 0;
    }
    else if (dir == 4) {
        if (x == n - 1) return 0;
    }
    return 1;
}
void move(int dir) { 
    //주사위 굴리기
    int temp = dice[0]; 
    if (dir == 1) {
        //동쪽으로 굴리기
        y++;
        dice[0] = dice[3];
        dice[3] = dice[1];
        dice[1] = dice[2];
        dice[2] = temp;
    }
    else if (dir == 2) {
        //서쪽으로 굴리기
        y--;
        dice[0] = dice[2];
        dice[2] = dice[1];
        dice[1] = dice[3];
        dice[3] = temp;
    }
    else if (dir == 3) {
        //북쪽으로 굴리기
        x--;
        dice[0] = dice[4];
        dice[4] = dice[1];
        dice[1] = dice[5];
        dice[5] = temp;
    }
    else if (dir == 4) {
        //남쪽으로 굴리기
        x++;
        dice[0] = dice[5];
        dice[5] = dice[1];
        dice[1] = dice[4];
        dice[4] = temp;
    }
}
void play() {
    //게임 실행
    for (int i = 0; i < k; i++) {
        if (!judge(order[i])) continue;
        move(order[i]);

        if (map[x][y] == 0) {
            //칸이 0일때 주사위 아래 수가 칸에 복사
            map[x][y] = dice[1];
        }
        else {
            //칸이 0이 아니면 칸에 있는 수가 주사위 아래수로 복사, 칸에 쓰여있는 수는 0
            dice[1] = map[x][y];
            map[x][y] = 0;
        }
        cout << dice[0] << '\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> x >> y >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < k; i++) {
        cin >> order[i];
    }
    play();
}

