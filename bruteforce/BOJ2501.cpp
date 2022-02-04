#include <iostream>
#include <vector>
using namespace std;
int n, k;
vector<int> num;
int main()
{
	int cnt = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		if (n % i != 0) continue;
		else {
			num.push_back(i);
			cnt++;
		}
	}
	if (cnt < k) cout << "0";
	else cout << num[k - 1];
	return 0;
}

