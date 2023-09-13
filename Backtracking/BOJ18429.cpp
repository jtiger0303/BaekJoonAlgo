#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k, visit[10], num, arr[10];
vector<int> kit;
void dfs(int depth) {
    if (depth == n) {
        int sum = 500;
        for (int i = 0; i < kit.size(); i++) {
            int tmp = kit[i] - k;
            sum += tmp;
            if (sum < 500) return;
        }
        num++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (visit[i]) continue;
        visit[i] = 1;
        kit.push_back(arr[i]);
        dfs(depth + 1);
        kit.pop_back();
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
        cin >> arr[i];
    }
    dfs(0);
    cout << num << '\n';
    return 0;
}

