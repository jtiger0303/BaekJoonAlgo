#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
long long sum = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    while (m--) {
        sort(v.begin(), v.end());
        long long min = v[0] + v[1];
        v[0] = v[1] = min;
    }
    for (int i = 0; i < n; i++) {
        sum += v[i];
    }
    cout << sum << '\n';
    return 0;
    
}
