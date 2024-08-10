#include <iostream>
#include <cstring>
using namespace std;
int n;
char star[3072][6144];
void print(int y, int x, int n) {
    if (n == 3) {
        star[y][x] = '*';
        star[y + 1][x - 1] = '*';
        star[y + 1][x + 1] = '*';
        star[y + 2][x - 2] = '*';
        star[y + 2][x - 1] = '*';
        star[y + 2][x] = '*';
        star[y + 2][x + 1] = '*';
        star[y + 2][x + 2] = '*';
    }
    else {
        print(y, x, n / 2);
        print(y + n / 2, x - n / 2, n / 2);
        print(y + n / 2, x + n / 2, n / 2);
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    memset(star, ' ', sizeof(star));
    print(0, n - 1, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n - 1; j++) {
            cout << star[i][j];
        }
        cout << '\n';
    }
    return 0;
}
