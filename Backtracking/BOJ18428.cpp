#include <iostream>
#include <vector>
using namespace std;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
char board[7][7];
int n;
vector<pair<int, int>> teacher, candi;
bool check(int y, int x) {
    for (int i = 0; i < 4; i++) {
        int ny = y;
        int nx = x;

        while (ny >= 0 && ny < n && nx >= 0 && nx < n) {
            if (board[ny][nx] == 'O') break;
            if (board[ny][nx] == 'S') return false;
            
            ny += dy[i];
            nx += dx[i];
        }
        
    }
    return true;
}
void func(int idx, int cnt) {
    if (cnt == 3) {
        for (pair<int, int> b : teacher) {
            if (!check(b.first, b.second)) {
                return;
            }
        }
        cout << "YES\n";
        exit(0);
    }
    for (int i = idx; i < candi.size(); i++) {
        board[candi[i].first][candi[i].second] = 'O';
        func(i+1, cnt + 1);
        board[candi[i].first][candi[i].second] = 'X';
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
            if (board[i][j] == 'T') teacher.push_back({ i, j });
            if (board[i][j] == 'X') candi.push_back({ i, j });
        }
    }
    func(0, 0);
    cout << "NO\n";
    return 0;
}

