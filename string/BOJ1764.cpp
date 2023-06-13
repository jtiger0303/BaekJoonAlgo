#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
map<string, int> mp;
vector<string> v;
string str;
int n, m, cnt;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> str;
        mp[str]++;
    }

    for (int i = 0; i < m; i++) {
        cin >> str;
        mp[str]++;
    }

    for (auto c : mp) {
        if (c.second > 1) {
            cnt++;
        }
    }

    cout << cnt << '\n';

    for (auto c : mp) {
        if (c.second > 1) {
            cout << c.first << '\n';
        }
    }
    return 0;

}

