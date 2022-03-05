#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int main()
{
	cin >> n;
	vector<int> v(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];

	}
	sort(v.begin(), v.end(), greater<int>());//내림차순 정렬
	
	for (int i = 0; i < v.size(); i++) {
		if ((i + 1) % 3 != 0) sum += v[i];//3n번째는 할인!!//
	}
	cout << sum << '\n';
	return 0;

}