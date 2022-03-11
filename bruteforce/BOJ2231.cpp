#include <iostream>
using namespace std;
int n;
int part(int i) {//분해합을 구하는 과정//
    int sum = i;

    while (i) {
        sum += i % 10;
        i /= 10;
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 1; i < n; i++) {
        int sum = part(i);
        if (sum == n) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << "0" << '\n';
}

