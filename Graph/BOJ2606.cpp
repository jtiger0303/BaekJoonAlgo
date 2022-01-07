#include <iostream>
#include <map>
using namespace std;
int n, u, v;
int ret=0;
bool visit[101];
int a[101][101];
void dfs(int x) {
   
    visit[x] = 1;
    for (int i = 1; i <=n; i++) {
        if (a[x][i] == 1 && !visit[i]) {
            ret++;
            dfs(i);
            
        }
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k;
    cin >> n>> k;
    for (int i = 0; i < k; i++) {
        cin >> u >> v;

        a[u][v] = a[v][u] = 1;
    }
    dfs(1);
    cout << ret << '\n';
    
}
