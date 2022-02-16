#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n;
double temp;
priority_queue<double> pq;
vector<double> v;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (pq.size() == 7) {
            pq.push(temp);
            pq.pop();
        }
        else pq.push(temp);
    }
    while (pq.size()) {
        v.push_back(pq.top());
        pq.pop();
    }
    sort(v.begin(), v.end());
    for (double i : v) cout << i << '\n';
    return 0;
}

