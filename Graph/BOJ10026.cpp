#include <iostream>
#include <string>
using namespace std;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0,1, 0, -1 };
int n;
int visited[101][101];
string color[101];
void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if (!visited[ny][nx] && color[ny][nx] == color[y][x]) {
            visited[ny][nx] = 1;
            dfs(ny, nx);
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int normal = 0;
    int abnormal = 0;

    for (int i = 0; i < n; i++) {
        cin >> color[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                normal++;
                visited[i][j] = 1;
                dfs(i, j);
            }
        }
    }
    
    cout << normal << " ";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (color[i][j] == 'R') color[i][j] ='G';
        }
    }

    //초기화~~//
    fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                abnormal++;
                visited[i][j] = 1;
                dfs(i, j);
            }
        }
    }
    cout << abnormal;
    return 0;
}

