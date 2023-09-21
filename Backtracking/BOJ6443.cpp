#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int t;
string str;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> str;
		sort(str.begin(), str.end());

		do {
			cout << str << '\n';
		} while (next_permutation(str.begin(), str.end()));
	}
	return 0;
}

