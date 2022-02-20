#include <iostream>
using namespace std;
int n;
int a = 150;
int b = 60;
int c = 10;
int main()
{
    bool check = true;
    int countA = 0;
    int countB = 0;
    int countC = 0;

    cin >> n;
    while (check) {
        if (n >= a) {
            countA += n / a;
            n = n % a;
        }
        else if (n >= b) {
            countB += n / b;
            n = n % b;
        }
        else if (n >= c) {
            countC += n / c;
            n = n % c;
        }
        else check = false;
    }
    if (!n) cout << countA << " " << countB << " " << countC << '\n';
    else cout << "-1" << '\n';
    return 0;
}

