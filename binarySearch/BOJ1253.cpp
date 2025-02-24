#include <iostream>
#include <algorithm>
using namespace std;
int n;
long long arr[2005];
int ret = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    if (n <= 2) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        int s = 0;
        int e = n - 1;
        while (s < e) {
            int sum = arr[s] + arr[e];

            if (sum < arr[i]) {
                s++;
            }
            else if (sum > arr[i]) {
                e--;
            }
            else {
                if (s == i) s++;
                else if (e == i) e--;
                else {
                    ret++;
                    break;
                }
            }
        }
    }

    cout << ret << '\n';
    return 0;
}
