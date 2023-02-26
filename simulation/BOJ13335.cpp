#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int n, w, l;
int a[1001];
queue<int> q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> w >> l;
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        while (1) {
            if (q.size() == w) {
                //다리의 길이와 같을 때
                sum -= q.front();
                q.pop();
            }
            if (a[i] + sum <= l) {
                break;
            }
            q.push(0); //무게가 넘어갈 때
            ans++;
        }
        q.push(a[i]);
        sum += a[i];
        ans++;
    }

    cout << ans + w << '\n'; //마지막 차가 통과할 떄
    return 0;
}

