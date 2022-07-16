#include <iostream>
using namespace std;
int a, i, mel;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> i;
    mel = a * (i - 1) + 1;
    cout << mel;
    return 0;
}

