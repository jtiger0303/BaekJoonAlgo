#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a, b;
int arr[500000], arr2[500000];
vector<int> v1;
vector<int> ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b;

    for (int i = 0; i < a; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < b; i++) {
        cin >> arr2[i];
        v1.push_back(arr2[i]);
    }
    sort(v1.begin(), v1.end());

    for (int i = 0; i < a; i++) {
        if (!binary_search(v1.begin(), v1.end(), arr[i])) {
            ans.push_back(arr[i]);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int i : ans) {
        cout << i << ' ';
    }
    return 0;

}

