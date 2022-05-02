#include <iostream>
#include <string>
using namespace std;
string str;
int cnt[26];
int main()
{
	cin >> str;
	string alphabet = "abcdefghijklmnopqrstuvwxyz";

	for (int i = 0; i < 26; i++) {
		cout << (int)str.find(alphabet[i])<<' '; //int로 변환해주어야 없을 때 -1반환//
	}
	return 0;
	

}

