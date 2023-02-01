#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;
unordered_set<string> s;
int n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    while (n--) {
        string name, log;
        cin >> name >> log;
        if (log == "enter") s.insert(name);
        else s.erase(name);
    }
    vector<string> ans(s.begin(), s.end());
    sort(ans.begin(), ans.end(), greater<string>());
    for (auto x : ans) cout << x << '\n';

}

