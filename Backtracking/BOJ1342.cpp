#include <iostream>
#include <string>
using namespace std;
string str;
int a[27];
int num = 0;
void func(int depth, string cur) {
    if (depth == str.size()) {
        num++;
        return;
    }
    for (int i = 0; i < 26; i++) {
        if (a[i] == 0) continue;
        if (cur != "" && cur[cur.size() - 1] == (char)('a' + i)) continue;
        a[i]--;
        func(depth + 1, cur + (char)('a' + i));
        a[i]++;
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        a[str[i] - 'a']++;
    }
    func(0, "");
    cout << num << '\n';
    return 0;
}

