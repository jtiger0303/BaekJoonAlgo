#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
map<string, int> _map;
map<int, string> _map2;
string s;
int n,m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s;
        _map[s] = i + 1; //string에는 int
        _map2[i + 1] = s;   //int에는 string
    }

    for (int i = 0; i < m; i++) {
        cin >> s;
        if (atoi(s.c_str()) == 0) {
            cout << _map[s] << '\n';
        }
        else {
            cout << _map2[atoi(s.c_str())] << '\n';
        }
    }
}

