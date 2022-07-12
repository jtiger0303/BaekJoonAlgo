#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n, t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> v(n);
        int result = 0;

        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size()-2; i++) {
            result = max(result, abs(v[i] - v[i + 2]));
        }
        cout << result<<'\n';
    }
    return 0;
}
