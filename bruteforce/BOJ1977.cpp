#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, sum=0;
int cnt = 0;
vector<int> v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    
    cin >> m >> n;
    for (int i = 1; i <= 100; i++) {
        num = i * i;
        if (m <= num && num <= n) {
            v.push_back(num);
            cnt++;
        }
    }
    if (cnt == 0) {
        cout << "-1" << '\n';
        return 0;
    }
    
    for (int a : v) {
        sum += a;
    }
    cout << sum << '\n';
    cout << v[0] << '\n';
    
}

