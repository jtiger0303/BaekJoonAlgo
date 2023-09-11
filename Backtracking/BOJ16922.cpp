#include <iostream>
#include <set>
using namespace std;
int n, num;
set<int> s;
int ret[4] = { 1, 5, 10, 50 };
void func(int begin, int cnt, int sum) {
    if (begin >= 4) return;
    if (cnt == n) {
        if (s.find(sum) == s.end()) {
            s.insert(sum);
            num++;
        }
        return;
    }
    func(begin+1, cnt + 1, sum + ret[begin]);
    func(begin, cnt + 1, sum + ret[begin]);
    func(begin+1, cnt, sum);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    func(0, 0, 0);
    cout << num << '\n';
    return 0;
}

