#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string a, b, res;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b;

    for (int i = 2; i >= 0; i--) {
        if (a[i] == b[i]) continue;
        if (a[i] > b[i]) {
            res = a;
            break;
        }
        else {
            res = b;
            break;
        }
    }

    cout << res[2] << res[1] << res[0];
    
    return 0;

    
}

