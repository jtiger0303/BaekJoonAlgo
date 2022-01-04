#include <iostream>
#include <vector>
using namespace std;

int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector <int> arr(n);
    vector <int> coin(k + 1);

    for (int i = 1; i <= k; i++) {
        coin[i] = 10001;
    }
    for (int i = 0; i <n; i++) {
        cin >> arr[i];
    }
    coin[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = arr[i]; j <= k; j++) {
            coin[j] = min(coin[j], coin[j - arr[i]] + 1);
        }
    }
    if (coin[k] == 10001) {
        cout << -1 << '\n';
    }
    else {
        cout << coin[k] << '\n';
    }
    
    return 0;
}

