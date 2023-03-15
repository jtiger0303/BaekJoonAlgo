#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> positive, negative;
int n, num;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (num > 0) positive.push_back(num);
        else negative.push_back(num);
    }

    sort(positive.begin(), positive.end(), greater<int>()); //양수는 내림차순 정렬
    sort(negative.begin(), negative.end()); //음수는 내림차순

    if (positive.size() % 2 != 0) ans += positive[positive.size() - 1]; //양수가 홀수 개일 경우에는 가장 마지막 수+
    for (int i = 0; i < positive.size() - 1; i+=2) {
        //양수의 경우
        if (positive[i + 1] == 1) ans += positive[i] + positive[i + 1];
        else if(positive[i+1]>0) ans += positive[i] * positive[i + 1];
    }

    if (negative.size() % 2 != 0) ans += negative[negative.size() - 1];
    for (int i = 0; i < negative.size() - 1; i += 2) {
        //음수의 경우
        ans += negative[i] * negative[i + 1];
    }
    cout << ans << '\n';
    return 0;
}

