#include <iostream>
#include <queue>
using namespace std;
int num, sum, zcnt, n;
priority_queue<int> ppq; // 내림차순 (1보다 클 때)
priority_queue<int, vector<int>, greater<int>> npq; // 오름차순(음수)
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num;

        if (num > 0) {
            ppq.push(num);
        }
        else if (num == 0) {
            zcnt++;
        }
        else npq.push(num);
    }

    while (ppq.size()) {
        int cur = ppq.top();
        ppq.pop();
        
        if (cur > 1 && ppq.size() && ppq.top() > 1) {
            sum += cur * ppq.top();
            ppq.pop();
        }
        else {
            sum += cur;
        }
    }

    while (npq.size()) {
        int cur = npq.top();
        npq.pop();

        if (npq.size()) {
            sum += cur * npq.top();
            npq.pop();
        }
        else if (!zcnt) {
            // 0이 없다면 음수 중 절댓값이 가장 작은 것을 더함
            sum += cur;
        }
    }
    cout << sum << '\n';
    return 0;
}
