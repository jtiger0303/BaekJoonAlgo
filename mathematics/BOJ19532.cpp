#include <iostream>
using namespace std;
int a, b, c, d, e, f;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b >> c >> d >> e >> f;

    int x = (c * e - b * f) / (a * e - b * d);
    int y = (a * f - c * d) / (a * e - b * d);

    cout << x << ' ' << y;
    return 0;
}

