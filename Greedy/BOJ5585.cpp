#include <iostream>
using namespace std;
int n;
int money[6] = { 500, 100, 50, 10, 5, 1 };
int main()
{
    int sum = 0;
    cin >> n;
    n = 1000 - n;
    
    for (int i = 0; i < 6; i++) {
        if (money[i] <= n) {
            sum += n / money[i];
            n = n % money[i];
        }
        
    }
    cout << sum << '\n';
    return 0;
}

