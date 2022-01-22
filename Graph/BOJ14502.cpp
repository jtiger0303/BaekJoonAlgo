#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
using namespace std;
typedef pair<int, int> pi;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int n, m, a[10][10];
int visited[10][10];
vector<pi> v;
void dfs(int y, int x) {
	if (a[y][x] == 1 || visited[y][x]) return;
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		dfs(ny, nx);
	}
}
int solve() {
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 2) dfs(i, j);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && a[i][j] == 0) ans++;
		}
	}
	return ans;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (!a[i][j]) v.push_back(pi(i, j));//벽을 세울 수 있는 후보군
		}
	}
	assert(v.size() >= 3);
	int ans = 0;//조합 3개=3중 for문
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < i; j++) {
			for (int k = 0; k < j; k++) {
				a[v[i].first][v[i].second] = a[v[j].first][v[j].second] = a[v[k].first][v[k].second] = 1;//벽 생성//
				ans = max(ans, solve());
				a[v[i].first][v[i].second] = a[v[j].first][v[j].second] = a[v[k].first][v[k].second] = 0;//벽 해제-->초기화//
			}
		}
	}
	cout << ans;
}

