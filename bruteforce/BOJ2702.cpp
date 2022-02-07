#include <iostream>
using namespace std;
int t, n, m;
int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> m;    
        cout << lcm(n, m) <<" "<< gcd(n, m) << '\n';
    }
   
    return 0;

}

