#include <iostream>
using namespace std;
int col[15], n, sum = 0;
bool check(int level) {
    for (int i = 0; i < level; i++) {
        if (col[i] == col[level] || abs(col[level] - col[i]) == level - i){
            //같은 줄에 있거나, 대각선에 위치해 있을 떄//
            return false;
        }
    }
    return true;
}
void nqueen(int x) {
    if (x == n) sum++;
    else {
        for (int i = 0; i < n; i++) {
            col[x] = i;//말을 배치
            if (check(x)) {
                nqueen(x + 1);
            }
        }
    }
}
int main()
{
    cin >> n;
    nqueen(0);
    cout << sum << '\n';
    return 0;
}

