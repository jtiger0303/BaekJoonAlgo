#include <iostream>
#include <vector>
using namespace std;
int n, m, k;
vector<int> know; //진실을 아는 사람
vector<vector<int>> v(50);
int parent[51];
int find(int x) {
    if (parent[x] == x) return x;
    return x = find(parent[x]);
}
void Union(int x, int y) {
    x = find(x);
    y = find(y);
    parent[x] = y;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;

    while (k--) {
        int t;
        cin >> t;
        know.push_back(t);
    }

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int p; //파티에 참가하는 사람의 수
        cin >> p;
        int num;
        int prev;

        for (int j = 0; j < p; j++) {
            if (j >= 1) {
                prev = num;
                cin >> num;
                Union(prev, num);
            }
            else {
                cin >> num;
            }
            v[i].push_back(num);
        }
    }
    for (auto& list : v) {
        bool flag = false;
        for (auto& person : list) {
            if (flag) break;
            for (auto& t : know) {
                if (find(person) == find(t)) {
                    flag = true;
                    break;
                }
            }
        }
        if (flag) m--;
    }
    cout << m << '\n';
    return 0;


}

