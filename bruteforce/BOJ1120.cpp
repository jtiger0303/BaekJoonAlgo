#include <iostream>
#include <string>
using namespace std;
string a, b;
int cnt;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int min = 50;
	cin >> a >> b;
	
	//얼마나 A가 B에 가장 많이 중첩이 되는가??//
	for (int i = 0; i <=b.length() - a.length(); i++) {
		cnt = 0;
		for (int j = 0; j < a.length(); j++) {
			if (a[j] != b[i + j]) cnt++;
		}
		min = min >= cnt ? cnt : min;
	}
	cout << min << '\n';
	return 0;
}

