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

    vector<int> arr(n);
    vector<int> coin(k + 1);

    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    coin[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = arr[i]; j <= k; j++) {
            coin[j] += coin[j - arr[i]];
        }
    }
    cout << coin[k] << endl;
    return 0;

}
