#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n;
int a, b;
int friends[51][51];
vector<int> v;
int main()
{
    //다익스트라/플로이드-워셜 문제!!//
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            else friends[i][j] = 1000;
        }
        
    }

    while (1) {
        cin >> a >> b;
        if (a == -1 && b == -1) break;
        friends[a][b] = friends[b][a] = 1;
    
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                friends[i][j] = min(friends[i][j], friends[i][k] + friends[k][j]);
            }
        }
    }
    int ans = 1000;
    for (int i = 1; i <= n; i++) {
        int tmp = 0;
        for (int j = 1; j <= n; j++) {
            tmp = max(tmp, friends[i][j]);
        }
            if (tmp < ans) {    //지금 후보보다 점수가 작을 때
                v.clear();
                ans = tmp;
                v.push_back(i); //회장 후보
            }
            else if (tmp == ans) {
                v.push_back(i);
            }
}
    sort(v.begin(), v.end());
    cout << ans << ' ' << v.size() << '\n';
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    return 0;
}

