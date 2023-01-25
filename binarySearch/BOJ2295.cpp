﻿#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int a[1001];
vector<int> v;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			v.push_back(a[i] + a[j]);
		}
	}
	sort(v.begin(), v.end());
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (binary_search(v.begin(), v.end(), a[i] - a[j])) {
				cout << a[i];
				return 0;
			}
		}
	}
}

