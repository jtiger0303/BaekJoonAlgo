#include <iostream>
#include <vector>
using namespace std;
int t, n, m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while (t--) {
        cin >> n;

        vector<int> arr(n);
       
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cin >> m;
        vector<int> coin(m + 1);
        coin[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = arr[i]; j <= m; j++) {
                coin[j] += coin[j - arr[i]];
            }
        }
        cout << coin[m] << '\n';
    }
    return 0;
}

