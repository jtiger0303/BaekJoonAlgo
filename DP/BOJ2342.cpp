#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
int dp[5][5][100001];
int n;
vector<int> v;
int check(int from, int to) {
    //처음에는 2
    if (from == 0) return 2;
    //다시 누르면 1
    if (from == to) return 1;
    //반대일 때 4
    if (abs(from - to) == 2) return 4;
    //인접할 경우
    return 3;
}
int solve(int y, int x, int target) {
    if (target == n) return 0;

    if (dp[y][x][target] != -1) return dp[y][x][target];

    //y가 왼쪽으로 갔다!!
    int left = solve(v[target], x, target + 1) + check(y, v[target]);
    int right = solve(y, v[target], target + 1) + check(x, v[target]);
    return dp[y][x][target] = min(left, right);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        int num;
        cin >> num;
        if (num == 0) break;
        v.push_back(num);
    }
    memset(dp, -1, sizeof(dp));
    n = v.size();
    cout << solve(0, 0, 0) << '\n';
    return 0;
}

