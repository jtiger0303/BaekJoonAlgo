#include <iostream>
using namespace std;
int n;
void star(int y, int x, int n) {
    if (n == 1) {
        cout << "*";
        return;
    }
    else if ((y / (n / 3)) % 3 == 1 && (x / (n / 3)) % 3 == 1) {
        cout << " ";
    }
    else {
        star(y, x, n / 3);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            star(i, j, n);
        }
        cout << '\n';
    }
    return 0;
}

