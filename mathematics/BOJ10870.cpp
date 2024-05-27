#include <iostream>
using namespace std;
int n;
int fibo(int n) {
    if (n == 0 || n == 1) return n;
    return fibo(n - 1) + fibo(n - 2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cout << fibo(n) << '\n';
    return 0;
}
