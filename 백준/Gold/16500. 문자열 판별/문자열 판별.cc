#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool dp[101];
int n;
string str;
vector<string> A;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str >> n;

    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        A.push_back(tmp);
    }

    for (int i = 0; i < str.length(); i++) {
        if (dp[i] || i == 0) {
            int st = i;
            for (int j = 0; j < n; j++) {
                // 입력한 문자열의 길이보다 긴 경우 continue
                if (st + A[j].length() > str.length()) continue;
                bool flag = 1;

                for (int k = 0; k < A[j].length(); k++) {
                    if (A[j][k] != str[st + k]) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    dp[st + A[j].length()] = 1;
                }
            }
        }
    }
    cout << dp[str.length()] << '\n';
    return 0;
}

