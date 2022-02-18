#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int main()
{
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    int realtime = a[0].first + a[0].second;
    for (int i = 1; i < a.size(); i++) {
        realtime = max(realtime, a[i].first);
        realtime += a[i].second;
    }
    cout << realtime << '\n';
    return 0;
}

