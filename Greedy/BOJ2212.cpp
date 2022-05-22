#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    vector<int> v(n);
    vector<int> dist(n-1);
    int sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i <n-1; i++) {
        dist[i] = v[i + 1] - v[i];
    }
    sort(dist.begin(), dist.end());
    for (int i = 0; i < n - k; i++) {
        sum += dist[i];
    }
    cout << sum << '\n';
    return 0;
}

