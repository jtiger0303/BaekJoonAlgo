#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
pair<int, int> gredient[10];
pair<int, int> ret[10];
int n;
int answer = 987654321;
void func(int idx, int cnt) {
    if (cnt > 0) {
        int a = ret[0].first; //신맛
        int b = ret[0].second; //쓴맛

        for (int i = 1; i < cnt; i++) {
            a *= ret[i].first;
            b += ret[i].second;
        }
        answer = min(answer, abs(a - b));
    }

    if (cnt == n) {
        return;
    }
    //조합 구현
    for (int i = idx; i < n; i++) {
        ret[cnt] = { gredient[i].first, gredient[i].second };
        func(i + 1, cnt + 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> gredient[i].first >> gredient[i].second;
    }
    func(0, 0);
    cout << answer << '\n';
    return 0;
}

