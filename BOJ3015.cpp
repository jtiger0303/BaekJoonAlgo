#include <iostream>
#include <stack>
using namespace std;
typedef long long LL;
LL n, ret, temp;
stack<pair<LL, LL>> s;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        int cnt = 1;
        while (s.size() && s.top().first <= temp) {//내림차순 아닐때
            ret += s.top().second;
            if (s.top().first == temp) {
                cnt = s.top().second + 1;
            }
            else {
                cnt = 1;
            }
            s.pop();
        }
        if (s.size()) ret++;
        s.push({ temp, cnt });
    }
    cout << ret << '\n';
    return 0;
}

