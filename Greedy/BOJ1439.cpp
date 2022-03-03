#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s;
int count0 = 0, count1 = 0;
int main()
{
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != s[i + 1]) {
            if (s[i] == '0') count0++;
            else if (s[i] == '1') count1++;
        }
    }
    cout << min(count0, count1) << '\n';
    return 0;
}

