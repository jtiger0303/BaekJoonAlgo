#include <iostream>
using namespace std;
int n, com1, com2;
int tour(int ret, int a, int b) {
    int round = 1;
    if (ret < 2 || ret>100000) return 0;
    while (ret) {
        if ((a + 1) / 2 == (b + 1) / 2) break;
        a = (a + 1) / 2;
        b = (b + 1) / 2;
        round++;
        ret / 2;
    }
    if (!ret) {
        return -1;
    }
    return round;
}
int main()
{
    cin >> n >> com1 >> com2;
    cout << tour(n, com1, com2) << '\n';
    return 0;
}

