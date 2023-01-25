#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int arr[1000000];
vector<int> v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        v.push_back(arr[i]);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end()); //중복 원소 제거

    for (int i = 0; i < n; i++) {
        int idx = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
        cout << idx << ' ';
    }
    return 0;
}

