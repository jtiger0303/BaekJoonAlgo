#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b;

    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '6') {
            a[i] = '5';
        }
    }

    for (int i = 0; i < b.size(); i++) {
      if (b[i] == '6') {
            b[i] = '5';
        }
    }
    cout << stoi(a) + stoi(b) << ' ';

    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '5') {
            a[i] = '6';
        }
    }

    for (int i = 0; i < b.size(); i++) {
        if (b[i] == '5') {
            b[i] = '6';
        }
    }
    cout << stoi(a) + stoi(b) << '\n';
    return 0;
}

