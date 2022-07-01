#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int cnt[200], flag;
char mid;
string s, ret;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    for (char a : s) {
        cnt[a]++;
    }
    for (int i = 'Z'; i >= 'A'; i--) {
        if (cnt[i]) {
            if (cnt[i] & 1) {
                //홀수는 2진수로 항상 끝이 '1'
                mid = (char)i;
                flag++;
                cnt[i]--;
            }
            if (flag == 2) break;
            for (int j = 0; j < cnt[i]; j += 2) {
                ret = (char)i + ret;
                ret += (char)i;
            }
        }
    }
    if (mid) ret.insert(ret.begin() + ret.size() / 2, mid);
    if (flag == 2) cout << "I'm Sorry, Hansso\n";
    else cout << ret << '\n';
    return 0;
}

