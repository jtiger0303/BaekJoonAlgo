#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
long long ans, n;
long long arr[27];
vector<long long> v;
string s;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		int ret = 1;
		for (int j = s.size() - 1; j >= 0; j--) {
			arr[s[j] - 'A'] += ret;
			ret *= 10;
		}
	}
	for (int i = 0; i < 27; i++) {
		if (arr[i] != 0) v.push_back(arr[i]);
	}
	sort(v.begin(), v.end());
	int value = 9;
	for (int i = v.size() - 1; i >= 0; i--) {
		ans += v[i] * value;
		value--;
	}
	cout << ans << '\n';
	return 0;
}

