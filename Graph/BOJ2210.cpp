#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int visited[5][5];
int a[5][5];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
vector<int> v;
void go(int y, int x, int num, int cnt) {
    if (cnt == 6) {
        v.push_back(num);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5) continue;
        if (!visited[ny][nx]) {
            go(ny, nx, num*10+a[ny][nx], cnt + 1);
        }
    }
   
}
int main()
{
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> a[i][j];
        }
   }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            go(i, j, a[i][j], 1);
        }
   }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());//중복된 값 삭제//

    cout << v.size();
    
}

