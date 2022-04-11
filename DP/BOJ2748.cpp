#include <iostream>
using namespace std;
long long fb[91], n;
int main()
{
    cin >> n;

    fb[0] = 0;
    fb[1] = 1;

    for (int i = 2; i <= n; i++) {
        fb[i] = fb[i - 1] + fb[i - 2];
    }
    cout << fb[n] << '\n';
    return 0;
}

