#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <utility>
using namespace std;
int n, m, k, ans;
set<string> check[11];
string s;
void func(string s, int cnt) {
    string after = s;
    int x = stoi(s); //string으로 받은 숫자

    if (cnt == k) {
        ans = max(x, ans);
        return;
    }

    for (int i = 0; i < m - 1; i++) {
        for (int j = i+1; j < m; j++) {
            if (i == 0 && after[j] == '0') continue; //첫 번째 자리와 0을 바꿀 수 없음
            swap(after[i], after[j]); //자리 바꾸기

            if (!check[cnt].count(after)) {
                //check 안에 없는 값일 경우
                check[cnt].insert(after);
                func(after, cnt + 1);
            }
            swap(after[i], after[j]); //원상복구
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s>>k;

    m = s.size();
    n = stoi(s);

    if (m == 1 || (m == 2 && s[1] == '0')) {
        //자릿수가 하나이거나 일의 자리 수가 0일때
        cout << -1 << '\n';
        return 0;
    }
    else {
        func(s, 0);
        cout << ans;
    }
    return 0;

}

