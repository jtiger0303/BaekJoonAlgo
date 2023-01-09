#include <iostream>
#include <queue>
using namespace std;
int visited[502];
int friends[502][502];
queue<int> q;
int n, m, a, b, cnt;
void bfs(int x) {
	visited[x] = 1;
	q.push(x);
	while (q.size()) {
		int here = q.front();
		q.pop();
		if (here != 1) { //상근이의 직접적인 친구가 아닌 경우
			for (int i = 2; i <= n; i++) {
				if (friends[here][i] == 1 && !visited[i]) {
					visited[i] = visited[here]+1;
					cnt++;
					continue;
				}
			}
		}
		else {
			for (int i = 1; i <= n; i++) {
				if (friends[1][i] == 1 && !visited[i]) {
					q.push(i);
					visited[i] = visited[here] + 1;
					cnt++;
				}
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		friends[a][b] = friends[b][a] = 1;
	}
	bfs(1);
	cout << cnt << '\n';
	return 0;
}

