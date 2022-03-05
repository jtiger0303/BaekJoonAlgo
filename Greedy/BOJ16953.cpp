#include <iostream>
using namespace std;
int a, b, cnt=0;
int main()
{	//거꾸로 계산하는 방식//
	cin >> a >> b;

	while (true) {
		if (a > b) {
			cout << "-1" << '\n';
			break;
		}
		if (a == b) {
			cnt++;
			cout << cnt << '\n';
			break;
		}
		if (b % 10 == 1) {
			b--;
			b /= 10;
		}
		else if (b % 2 == 0) {
			b /= 2;
		}
		else {
			cout << "-1" << '\n';
			break;
		}
		cnt++;

	}
	
}

