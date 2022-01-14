#include <iostream>
#include <queue>
using namespace std;
int n, m, p, s;
int num1, num2;
int visited[101];
int a[101][101];
int depth[101];
queue<int> q;
void bfs(int i) {
	visited[i] = 1;
	q.push(i);
	while (q.size()) {
		int x = q.front();
		q.pop();

		for (int j = 1; j <= n; j++){
			if (a[x][j] == 1 && !visited[j]) {
				visited[j] = 1;
				q.push(j);
				depth[j] = depth[x] + 1;
			}
		} 
	}
	return;
}
int main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> p >> s;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> num1 >> num2;
		a[num1][num2] = a[num2][num1]=1;
	}
	bfs(p);

	if (depth[s] == 0) cout << -1 << '\n';
	else cout << depth[s];

	return 0;
}
