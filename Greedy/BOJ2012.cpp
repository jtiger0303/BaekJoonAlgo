#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
long long sum;
vector<int> v(500005);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    v.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    
    for (int i = 0; i < n; i++) {
        sum += abs(v[i] - (i + 1));
    }
    cout << sum << '\n';
    return 0;
}
