#include <iostream>
#include <queue>
using namespace std;
int n, k;
queue<int> q;
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    int cnt = 1;

    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    cout << "<";
    while (q.size() > 1) {
        if (cnt == k) {
            cout << q.front() << ", ";
            q.pop();
            cnt = 1;
        }
        else {
            q.push(q.front());
            q.pop();
            cnt++;
        }
    }
    cout << q.front() << ">\n";
    return 0;

}

