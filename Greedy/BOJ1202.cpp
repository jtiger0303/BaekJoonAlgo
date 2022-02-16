#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
typedef long long LL;
using namespace std;
LL n, k, ret, temp1, temp;
int main()
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	priority_queue<LL> pq;
	vector<pair<LL, LL>> v(n);//보석
	vector<LL> vv(k);//가방
	
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	for (int i = 0; i < k; i++) cin >> vv[i];
	sort(v.begin(), v.end());
	sort(vv.begin(), vv.end());//무게 정렬

	int j = 0;
	for (int i = 0; i < k; i++) {
		while (j < n && v[j].first <= vv[i]) pq.push(v[j++].second);
		if (pq.size()) {
			ret += pq.top();
			pq.pop();
		}
	}
	cout << ret << '\n';
	return 0;
}

