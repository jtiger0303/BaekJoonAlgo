#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, cnt=0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	while (true) {
		int max=0, index;
		for (int i = 1; i < n; i++) {
			if (max < v[i]) {
				max = v[i];
				index = i;
			}
		}
		if (v[0] > max) {
			cout << cnt << '\n';
			break;
		}
		v[0]++;
		v[index] --;
		cnt++;
		
	}
	
	return 0;
}

