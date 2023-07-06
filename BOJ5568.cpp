#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int n, k, num;
set<string> st;
vector<string> ret;
vector<string> card;
int visit[11];
void dfs(int depth) {
    if (depth == k) {
        string str = "";
        for (auto c : ret) {
            str += c;
        }
        st.insert(str);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (visit[i]) continue;
        visit[i] = 1;
        ret.push_back(card[i]);
        dfs(depth + 1);
        ret.pop_back();
        visit[i] = 0;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        card.push_back(s);
    }
    dfs(0);
    cout << st.size() << '\n';
    return 0;
}

