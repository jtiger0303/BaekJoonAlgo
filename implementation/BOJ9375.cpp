#include <iostream>
#include <string>
#include <map>
using namespace std;
int t, n;
string a, b;
int main()
{
    cin >> t;
    while (t--) {
        map<string, int> _map;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            _map[b]++;
        }
        long long ret = 1;//경우의 수는 굉장히 많을 수 있다!!
        for (auto c : _map) {
            ret *= ((long long)c.second + 1);
        }
        ret--;
        cout << ret << '\n';
    }
    return 0;
}

