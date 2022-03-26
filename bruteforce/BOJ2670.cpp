#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
double a[10001], ret, k;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    double b = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > b * a[i]) {
            b = a[i];
            //곱할 필요 X//
        }
        else b *= a[i];
        ret = max(b, ret);
    }
    printf("%.3lf", ret + 0.00001);
    return 0;
}

