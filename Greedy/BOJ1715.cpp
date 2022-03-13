#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, temp, sum=0;
priority_queue<int, vector<int>, greater<int>> pq;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> temp;
        pq.push(temp);
    }
    while (pq.size() > 1) { //작은 것부터 정렬->합친 후 다시 pq에 넣는다//
        int a, b;
        
        a = pq.top();
        pq.pop();

        b = pq.top();
        pq.pop();

        sum += a + b;
        pq.push(a + b);
    }
    cout << sum << '\n';
    return 0;
}

