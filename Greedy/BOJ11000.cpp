#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;
int n, s, e;
vector<pair<int, int>> class_time; //시작 시간과 끝나는 시간
int solve(int cnt) {
    pq.push(class_time[0].second); //끝나는 시간 삽입

    for (int i = 1; i < cnt; i++) {
        pq.push(class_time[i].second);

        if (pq.top() <= class_time[i].first) {
            //top보다 시작 시간이 같거나 늦다면
            pq.pop();
        }
    }
    return pq.size();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s >> e;
        class_time.push_back({ s, e });
    }
    sort(class_time.begin(), class_time.end());
    cout<<solve(n)<<'\n';
    return 0;
}

