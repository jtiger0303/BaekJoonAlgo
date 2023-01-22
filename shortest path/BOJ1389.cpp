#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int a, b;
int friends[101][101];
vector<int> v; //베이컨의 수가 가장 적은 사람
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            friends[i][j] = 1000;
        }
    }
    
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
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
            tmp += friends[i][j];
        }
        if (tmp < ans) {
            v.clear();
            ans = tmp;
            v.push_back(i);
        }
        else if (tmp == ans) {
            v.push_back(i);
        }
    }
    sort(v.begin(), v.end());
    cout << v[0] << '\n';
    return 0;
}

