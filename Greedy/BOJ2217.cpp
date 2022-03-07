#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int answer = -98764321;
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
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		answer = max(answer, (n-i) * v[i]);//(n-i)는 로프가 가장 낮은 중량인 부분 리스트의 로프 개수//
	}
	cout << answer << '\n';
	return 0;
}

