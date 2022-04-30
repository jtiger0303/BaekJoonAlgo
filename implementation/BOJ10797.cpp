#include <iostream>
using namespace std;
int n, car;
int main()
{
    int sum = 0;
    cin >> n;
    for (int i = 0; i < 5; i++) {
        cin >> car;
        if (n == car) sum++;
    }
    cout << sum << '\n';
    return 0;
   
}

