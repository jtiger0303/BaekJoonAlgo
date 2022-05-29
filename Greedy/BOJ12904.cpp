#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s, t;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s >> t;
    int result = 0;
    
    //T에서 S를 추론해보자~~//
    while (true) {
        if (s.size() == t.size()) {
            if(s==t) result = 1;
            break;
        }
        if (t[t.size() - 1] == 'A') {
            t.pop_back();
        }
        else {
            t.pop_back();
            reverse(t.begin(), t.end());
        }
    }
    cout << result << '\n';
    return 0;
    
}

