#include <iostream>
#include <cmath>
using namespace std;
void cantor(int n) {
    if (n == 0) {
        cout << "-";
        return;
    }

    int size = pow(3, n - 1); // n이 1이면 1, 2이면 3
    cantor(n - 1);
    for (int i = 0; i < size; i++) {    // 공백 계산
        cout << " ";
    }
    cantor(n - 1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    
    while (cin >> n) {
        cantor(n);
        cout << '\n';
    }
    return 0;

}

