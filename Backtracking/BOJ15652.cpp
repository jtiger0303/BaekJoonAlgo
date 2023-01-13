#include <iostream>
using namespace std;
int a[8];
int n, m;
void go(int cnt, int num) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            cout << a[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = num; i <= n; i++) {
        a[cnt] = i;
        go(cnt + 1, i);
    }
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> n >> m;
    go(0, 1);
    return 0;
}

