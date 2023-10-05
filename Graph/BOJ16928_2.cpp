#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int n, m, visited[101], board[101], a, b;
queue<int> q;
void bfs(int here) {
    visited[here] = 1;
    q.push(here);

    while (q.size()) {
        int here = q.front();
        q.pop();

        for (int i = 1; i <= 6; i++) {
            //주사위 굴리기
            if (here + i == 100) {
                cout << visited[here] << '\n';
                return;
            }

            if (here + i < 100) {
                if (!visited[here + i]) {
                    if (board[here + i] != 0) {
                        //뱀이나 사다리가 존재하는 경우
                        if (!visited[board[here + i]]) {
                            q.push(board[here + i]);
                            visited[here + i] = visited[here] + 1;
                            visited[board[here + i]] = visited[here] + 1;
                        }
                    }
                    else {
                        //주사위 굴리기
                        q.push(here + i);
                        visited[here + i] = visited[here] + 1;
                    }
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
    
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        board[a] = b;
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        board[a] = b;
    }
    bfs(1);
    return 0;
}

