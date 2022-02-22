#include <iostream>
using namespace std;
long long s;
long long sum = 0;
int num = 1;
int result = 0;
int main()
{
    cin >> s;
    while (true) {
        sum += num;
        result++;
        if (sum > s) {
            result--;//값을 넘길 시에는 줄인다//
            break;
        }
        num++;
    }
    cout << result << '\n';
    return 0;
}

