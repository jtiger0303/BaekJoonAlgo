#include <iostream>
using namespace std;
int n, m, q;
int r[500001], c[500001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m >> q;

    while (q--) {
        int start, x, v;
        cin >> start >> x >> v;

        if (start == 1) {
            r[x] += v;
        }
        else {
            c[x] += v;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << r[i] + c[j] << ' ';
        }
        cout << '\n';
    }
    return 0;

}
