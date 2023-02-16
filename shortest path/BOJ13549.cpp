#include <iostream>
#include <queue>
#define MAX 200000
using namespace std;
int n, k;
int visited[MAX+1];
queue<int> q;
//가중치가 0, 1로 다르기 때문에 다익스트라!!//
void bfs(int here) {
    visited[here] = 1;
    q.push(here);

    while (q.size()) {
        int here = q.front();
        q.pop();

        if (here * 2 < MAX&&visited[here*2]>visited[here]) {
            visited[here * 2] = visited[here];
            q.push(here * 2);
        }

        if (here + 1 < MAX && visited[here + 1] > visited[here] + 1) {
            visited[here + 1] = visited[here] + 1;
            q.push(here + 1);
        }

        if (here - 1 >= 0 && visited[here - 1] > visited[here] + 1) {
            visited[here - 1] = visited[here] + 1;
            q.push(here - 1);
        }

    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    for (int i = 0; i < 200000; i++) {
        visited[i] = 200000;
    }
    bfs(n);
    cout << visited[k] - 1 << '\n';
    return 0;
}

