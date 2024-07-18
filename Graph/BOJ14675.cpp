#include <iostream>
#include <vector>
using namespace std;
int n, q, t, k, a, b;
vector<int> v[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    cin >> q;

    for (int i = 0; i < q; i++) {
        cin >> t >> k;
        if (t == 1) {   // 단절점인가? --> 트리는 리프 노드를 제외하고 모두 단절점이다
            if (v[k].size() > 1) {
                cout << "yes" << '\n';
            }
            else {
                cout << "no" << '\n';
            }
        }
        else {  // 단절선인가? --> 트리는 모두 단절선
            cout << "yes" << '\n';
        }
    }
    return 0;
}

