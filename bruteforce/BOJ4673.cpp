#include <iostream>
using namespace std;

bool check[10001];
int d(int num) {
    int temp;
    temp = num + num / 1000 + (num / 100) % 10 + (num % 100)/10 + num % 10;
    return temp;
}
void selfn() {
    int temp;
    check[1] = false;
    for (int i = 0; i < 10000; i++) {
        if (i < 10000) {
            temp = d(i);
            if (temp < 10000) check[temp] = true;
        }
    }
}
int main()
{
    selfn();
    for (int i = 1; i < 10000; i++) {
        if (!check[i]) {
            cout << i << '\n';
        }
    }
}

