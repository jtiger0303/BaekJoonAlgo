#include <iostream>
#include <algorithm>
using namespace std;
int t, n;
pair<int, int> employee[100000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> employee[i].first >> employee[i].second;
        }
        sort(employee, employee + n);
        int rank = employee[0].second;
        int result = 1;//합격자의 수(1등의 서류합격자는 무조건 합격)
        for (int i = 1; i < n; i++) {
            if (employee[i].second < rank) {
                result++;
                rank = employee[i].second;//업데이트
            }
        }
        cout << result << '\n';
    }
    return 0;
}

