#include <iostream>
#include <string>
using namespace std;
string s, ans;
int n, r;
int main()
{
    cin >> r;
    while (r--) {
        cin >> n>>s;
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < n; j++) {
                ans += s[i];
            }
        }
        cout << ans << '\n';
        ans.clear();
    }
    
    return 0;

}

