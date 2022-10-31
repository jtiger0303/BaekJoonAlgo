#include <iostream>
using namespace std;
int n;
int v[101];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int sum = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[n];
	}
	for (int i = n - 1; i >= 1; i--) {
		while (v[i] <= v[i - 1]) {
			v[i - 1] -= 1;
			sum++;
		}
	}
	cout << sum << '\n';
	return 0;
}

