#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<int> v;
string str;
int main()
{
    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        v.push_back(str[i]-'0');
    }
    sort(v.begin(), v.end(), greater<int>());

    for (int a : v) {
        cout << a;
    }
    return 0;
}

