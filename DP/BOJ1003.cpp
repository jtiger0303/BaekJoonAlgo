#include <iostream>
using namespace std;
int zero[41] = { 1, 0, };
int one[41] = { 0, 1, };

int main()
{
    int t, num;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> num;
        for (int j = 2; j <= num; j++) {
            zero[j] = zero[j - 1] + zero[j - 2];
            one[j] = one[j - 1] + one[j - 2];
        }
        cout << zero[num] << ' ' << one[num] << '\n';
    }
    return 0;
}

