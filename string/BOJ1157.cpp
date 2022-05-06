#include <iostream>
#include <string>
using namespace std;
int cnt[26];
string str;
char ans;
int main()
{
	cin >> str;
	int max = -1;
	for (char c : str) {
		if ('a' <= c && c <= 'z') {
			cnt[c - 'a']++;
		}
		else if ('A' <= c && c <= 'Z') {
			cnt[c -'A']++;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (max < cnt[i]) {
			max = cnt[i];
			ans = (char)(i + 65);
		}
		else if (max == cnt[i]) ans = '?';
	}
	cout << ans << '\n';
	return 0;
}

