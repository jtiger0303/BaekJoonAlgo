﻿#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, temp;
int check(int temp, vector<int>& v) {
    int lo = 0, r = v.size() - 1;
    int mid;

    while (lo <= r) {
        mid = (lo + r) / 2;
        if (v[mid] > temp) r = mid - 1;
        else if (v[mid] == temp) return 1;
        else lo = mid + 1;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> temp;
        cout << check(temp, v) << '\n';
    }
    return 0;
}

