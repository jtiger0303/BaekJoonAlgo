#include <iostream>
#include <vector>
using namespace std;
int n, m;
int sum = -987654321;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count = 0;
    cin >> n >> m;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (v[i] + v[j] + v[k] <= m && v[i] + v[j] + v[k] > sum) {
                    sum = v[i] + v[j] + v[k];
                }
            }
        }
    }

    cout << sum << '\n';
    return 0;
}

