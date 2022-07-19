#include <iostream>
#include <vector>
using namespace std;
int n, m, k, t1, t2, t3;
long long t4;
long long sum(vector<long long>& tree, int i) {
    long long ans = 0;
    while (i > 0) {
        ans += tree[i];
        i -= (i & -i);
    }
    return ans;
}
void update(vector<long long>& tree, int i, long long diff) {
    while (i < tree.size()) {
        tree[i] += diff;
        i += (i & -i);
    }
}
int main()
{   
    //n=수의 개수, m=수의 변경이 일어나는 횟수, k=구간의 합을 구하는 횟수//
    cin >> n >> m >> k;
    vector<long long> a(n + 1);
    vector<long long> tree(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        update(tree, i, a[i]);
    }
    m += k;
    while (m--) {
        cin >> t1;
        if (t1 == 1) {
            cin >> t2 >> t4;
            long long diff = t4 - a[t2];
            a[t2] = t4;
            update(tree, t2, diff);
        }
        else {
            int t2, t3;
            cin >> t2 >> t3;
            cout << sum(tree, t3) - sum(tree, t2 - 1)<<'\n';
        }
    }
    return 0;

}

