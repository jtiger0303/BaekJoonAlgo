#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, k;
int main()
{
    int sum = 0;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = n-1; i >= 0; i--) {
        while (k - v[i] >= 0) {
            sum++;
            k -= v[i];
        }
    }
    cout << sum << '\n';
    return 0;
}

