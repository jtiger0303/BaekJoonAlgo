#include <iostream>
using namespace std;
int A, B, C, a, b, cnt[104], ret;
int main()
{
    cin >> A >> B >> C;
    for (int i = 0; i < 3; i++) {
        cin >> a >> b;
        for (int j = a; j < b; j++) cnt[j]++;
    }
    for (int i = 1; i < 100; i++) {
        if (cnt[i]) {
            if (cnt[i] == 1) ret += A;
            else if (cnt[i] == 2) ret += 2 * B;
            else if (cnt[i] == 3) ret += 3 * C;
        }
    }
    cout << ret << '\n';
    return 0;
}

