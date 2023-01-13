﻿#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int a[8];
bool check[8];
vector<int> v;
void go(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		if (check[i]) continue;
		check[i] = true;
		a[cnt] = v[i];
		go(cnt + 1);
		check[i] = false;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		v.push_back(a[i]);
	}
	sort(v.begin(), v.end());
	go(0);
	return 0;
	
	
}

