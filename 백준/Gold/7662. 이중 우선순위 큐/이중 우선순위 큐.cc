#include <iostream>
#include <queue>
#include <map>
using namespace std;
int t;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    
    while (t--) {
        int k;
        cin >> k;
        priority_queue<int> maxQ; // 최대 힙
        priority_queue<int, vector<int>, greater<int>> minQ; // 최소 힙
        map<int, int> counter; // 삽입, 삭제 카운트

        for (int i = 0; i < k; i++) {
            char op;
            int n;
            cin >> op >> n;

            if (op == 'I') {
                maxQ.push(n);
                minQ.push(n);
                counter[n] ++;
            }
            else if (op == 'D') {
                if (n == 1) {
                    // 최댓값 삭제
                    while (maxQ.size() && counter[maxQ.top()] == 0) maxQ.pop();
                    if (maxQ.size()) {
                        counter[maxQ.top()]--;
                        maxQ.pop();
                    }
                }
                else {
                    // 최솟값 삭제
                    while (minQ.size() && counter[minQ.top()] == 0) minQ.pop();
                    if (minQ.size()) {
                        counter[minQ.top()]--;
                        minQ.pop();
                    }
                }
            }
        }

        // 최종 유효한 값만 남길 떄까지 pop
        while (maxQ.size() && counter[maxQ.top()] == 0) maxQ.pop();
        while (minQ.size() && counter[minQ.top()] == 0) minQ.pop();

        if (maxQ.empty() || minQ.empty()) cout << "EMPTY\n";
        else cout << maxQ.top() << " " << minQ.top() << "\n";
    }
    return 0;
}

