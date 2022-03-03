#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string n;
long long sum = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    sort(n.begin(), n.end(), greater<>());//문자열 내림차순 정렬//
    if (n[n.size() - 1] != '0') cout << "-1" << '\n';
    else {
        for (char c : n) {
            sum += c - '0';
        }
        if (sum % 3 == 0) {
            cout << n << '\n';
        }
        else cout << "-1" << '\n';
    }
    return 0;
}

