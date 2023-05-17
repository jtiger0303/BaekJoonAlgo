#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int n, m;
string str;
const int ROOT = 1;
int unused = 2;
const int MX = 10000 * 500 + 5;
bool chk[MX];
int nxt[MX][26];
int c2i(char c) {
    return c - 'a';
}
void insert(string& s) {
    int cur = ROOT;
    for (auto c : s) {
        if (nxt[cur][c2i(c)] == -1) {
            nxt[cur][c2i(c)] = unused++;
        }
        cur = nxt[cur][c2i(c)];
    }
    chk[cur] = true;
}
bool find(string& s) {
    int cur = ROOT;
    for (auto c : s) {
        if (nxt[cur][c2i(c)] == -1) {
            return false;
        }
        cur = nxt[cur][c2i(c)];
    }
    return chk[cur];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < MX; i++) {
        fill(nxt[i], nxt[i] + 26, -1);
    }

    while (n--) {
        cin >> str;
        insert(str);
    }

    int ans = 0;
    while (m--) {
        cin >> str;
        ans += find(str);
    }
    cout << ans << '\n';
    return 0;
}

