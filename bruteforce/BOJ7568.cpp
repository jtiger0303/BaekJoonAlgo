#include <iostream>
using namespace std;
pair<int, int> kh[50];
int n;
int main()
{
	int rank = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> kh[i].first >> kh[i].second;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((kh[i].first < kh[j].first) && kh[i].second < kh[j].second) {
				rank++;
			}
		}
		cout << rank << " ";
		rank = 1;
	}
	return 0;
}
