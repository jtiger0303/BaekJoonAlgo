#include <iostream>
#include <string>
using namespace std;
int a, b, c;
string ans;
int cnt[10];
int main()
{
    cin >> a >> b >> c;

    ans = to_string(a * b * c);
    for (int i = 0; i < ans.size(); i++) {
        cnt[ans[i] - '0']++;
    }

    for (int i = 0; i < 10; i++) {
        cout << cnt[i] << '\n';
    }
    return 0;
}

