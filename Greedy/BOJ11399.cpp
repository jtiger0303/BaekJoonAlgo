#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, ret=0;
int main()
{
    cin >> n;
    vector<int> v(n);
    vector<int> f(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < n; i++) {
        v[i] = v[i] + v[i - 1];
    }
    for (int i = 0; i < n; i++) {
        ret += v[i];
    }
    cout << ret << '\n';
    
   
    return 0;
}

