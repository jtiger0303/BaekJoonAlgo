#include <iostream>
using namespace std;
int n;
bool check(int num) {
	int num3, num2, num1;
	num3 = num / 100;
	num2 = (num / 10)%10;
	num1 = num % 10;
	if (num < 100||(num3-num2)==(num2-num1)) return true;
	return false;
}
int main()
{
	int cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (check(i)) cnt++;
	}
	cout << cnt << '\n';
	return 0;
   
}

