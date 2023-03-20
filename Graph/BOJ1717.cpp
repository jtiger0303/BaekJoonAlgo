#include <iostream>
using namespace std;
int board[1000005], n, m, order, a, b;
//union-find 문제//
int find(int parent[], int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent, parent[x]);
}
void Union(int parent[], int a, int b) {
    a = find(parent, a);
    b = find(parent, b);

    //더 작은 수로 합침
    if (a < b) parent[b] = a;
    else parent[a] = b;
}
bool isSameUnion(int parent[], int a, int b) {
    a = find(parent, a);
    b = find(parent, b);

    if (a == b) return 1;
    else return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i <= 1000000; i++) board[i] = i;

    for (int i = 0; i < m; i++) {
        cin >> order>>a>>b;

        if (order == 0) {
            Union(board, a, b);
        }
        else {
            cout << (isSameUnion(board, a, b) ? "YES" : "NO") << '\n';
        }
    }
}

