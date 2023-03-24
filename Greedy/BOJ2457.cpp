#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> v;
pair<int, int> a, b;
int n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a.first >> a.second >> b.first >> b.second;
        v.push_back({ 100 * a.first + a.second, 100 * b.first + b.second }); //날짜 만들기
    }
    sort(v.begin(), v.end());

    int idx = -1;
    int temp = 0;
    int result = 0;

    for (int i = 301; i <= 1130 && idx < n; i = temp) {
        bool flag = false;
        idx++;

        for (int j = idx; j < v.size(); j++) {
            if (v[j].first > i) {
                break; //꽃이 피는 시간이 오버될 경우 
            }
            if (temp < v[j].second) {
                temp = v[j].second;
                idx = j;

                flag = true;
            }
        }
        if (flag) {
            result++;

        }
        else {
            cout << 0 << '\n';
            return 0;
        }
    }
    cout << result << '\n';
    return 0;
}

