#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, res=0;
int s, w;
vector<pair<int, int>> egg; //내구도, 무게
void dfs(int idx) {
    if (idx >= n) {
        //손에 든 달걀이 가장 오른쪽에 있는 달걀일 때
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (egg[i].first <= 0) cnt++;
        }
        res = max(res, cnt);
        return;
    }
    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (idx == i) continue; //자기 자신 건너 뜀
        if (egg[idx].first > 0 && egg[i].first > 0) {
            egg[idx].first -= egg[i].second;
            egg[i].first -= egg[idx].second;
            flag = true;
            dfs(idx + 1);
            egg[idx].first += egg[i].second;
            egg[i].first += egg[idx].second;
        }
    }
    if (!flag) dfs(idx + 1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s >> w;
        egg.push_back({ s, w });
    }
    dfs(0);
    cout << res << '\n';
    return 0;
}

