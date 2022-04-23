#include <iostream>
typedef long long LL;
using namespace std;
int num;
LL fib[46] = {};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> num;
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= num; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    cout << fib[num] << '\n';
    return 0;
}

