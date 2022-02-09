#include <iostream>
using namespace std;
int n, f;
void turn(int num, int div) {
    int ans = 0;
    
    num /= 100;
    num *=100;
    while ((num + ans) % div != 0 && div <= 100) ans++;
    if (ans < 10) cout << "0" << ans;
    else cout << ans;

}
int main()
{
    cin >> n >> f;
    turn(n, f);
    return 0;
}

