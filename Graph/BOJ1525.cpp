#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
map<string, int> mp;
int board[3][3];
queue<string> q;
int bfs(string s) {
    q.push(s);

    while (q.size()) {
        string str = q.front();
        q.pop();

        if (str == "123456780") {
            return mp[str];
        }

        auto p = str.find('0');

        for (int i = 0; i < 4; i++) {
            int ny = p / 3 + dy[i];
            int nx = p % 3 + dx[i];

            if (ny < 0 || ny >= 3 || nx < 0 || nx >= 3) continue;
            string tmp = str;
            swap(tmp[p], tmp[3 * ny + nx]);
            if (!mp[tmp]) {
                // 만약 방문하지 않았다면
                mp[tmp] = mp[str] + 1;
                q.push(tmp);
            }
        }
    }

    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s = "";

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> board[i][j];
            s += board[i][j] + 48;
        }
    }

    cout << bfs(s) << '\n';
    return 0;
}
