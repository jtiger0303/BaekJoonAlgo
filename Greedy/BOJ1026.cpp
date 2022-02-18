#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int sum = 0;
int main()
{//A의 작은 수와 B의 큰 수를 곱하자//
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
        sum += a[i] * b[n - 1-i];
    }
    cout << sum << '\n';
    return 0;
}

