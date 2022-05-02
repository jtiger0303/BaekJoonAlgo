#include <iostream>
using namespace std;
char ch;
int sum = 0;
int n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ch;
        sum += ch - '0';
    }
    cout << sum << '\n';
    return 0;
}

