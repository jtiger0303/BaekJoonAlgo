#include <iostream>
#include <vector>
#include <algorithm>
typedef long long LL;
using namespace std;
int n;
vector<pair<LL, LL>> v;
LL sum[100001];
LL mini = 987654321;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        LL a, b;
        cin >> a >> b;
        v.push_back({ a, b });
    }

    sort(v.begin(), v.end());
    sum[0] = v[0].second;

    for (int i = 1; i < n; i++) {   // 누적합 구하기
        sum[i] = sum[i - 1] + v[i].second;
    }

    LL start = 0, end = n - 1;
    
    while (start <= end) {  
        LL mid = (start + end) / 2;
        if (sum[mid] >= sum[n - 1] - sum[mid]) {
            end = mid - 1;
            mini = min(mini, v[mid].first);
        }
        else {
            start = mid + 1;
        }
    }
    cout << mini << '\n';
    return 0;


}
