#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> dir;
queue<int> q;
int visited[1000001];
int f, s, u, g, d;
int dcnt = 0;
int ucnt=0;
void bfs(int here) {
    //내려가는 방향
    visited[here] = 1;
    q.push(here);

    while (q.size()) {
        int here = q.front();
        q.pop();

        for (int i = 0; i < 2; i++) {
            int there = here+dir[i];

            if (0 < there && there <= f) { 
                //층 안에 들어올때
                if (visited[there]) continue;
                visited[there] = visited[here] + 1;
                q.push(there);

            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> f >> s >> g >> u >> d;

    dir.push_back(u);
    dir.push_back(d * -1);

    bfs(s);
    if (visited[g]) {
        cout << visited[g]-1 << '\n';
    }
    else {
        cout << "use the stairs" << '\n';
    }
    return 0;
}

