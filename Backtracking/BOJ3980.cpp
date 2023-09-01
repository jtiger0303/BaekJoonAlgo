#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int t, visit[11], board[11][11];
int ret = 0;
int sum = 0;
void func(int cnt, int sum) {
    if (cnt == 11) {
        ret = max(ret, sum);
        return;
    }
    for (int i = 0; i < 11; i++) {
        if (board[cnt][i] == 0||visit[i]) continue; //능력치가 0인 포지션에 배치 불가
        visit[i] = 1;
        func(cnt + 1, sum + board[cnt][i]);
        visit[i] = 0;
    }
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while (t--) {
        memset(visit, 0, sizeof(visit));
        ret = 0;
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 11; j++) {
                cin >> board[i][j];
            }
        }
        func(0, 0);
        cout << ret << '\n';
    }
}

