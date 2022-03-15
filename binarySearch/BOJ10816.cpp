#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, temp;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> temp;
        auto l = lower_bound(v.begin(), v.end(), temp);//하한값 구하기//
        auto r = upper_bound(v.begin(), v.end(), temp);//상한값 구하기//
        cout << r - l << '\n';
    }
    return 0;
}

// -10 -10 2 3 3 6 7 10 10 10에서 3을 찾는다면 3의 하한의 인덱스는 3, 3의 상한은 6이므로 인덱스는 5이므로 3의 개수는 2이다.//