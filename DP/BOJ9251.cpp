#include <iostream>
#include <string>
using namespace std;
string str1, str2, tmp1, tmp2;
int lcs[1001][1001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> tmp1 >> tmp2;

    str1 = '0' + tmp1; //LCS 알고리즘을 위해 0을 붙여준다
    str2 = '0' + tmp2;

    for (int i = 0; i < str1.size(); i++) {
        for (int j = 0; j < str2.size(); j++) {
            if (i == 0||j==0) {
                lcs[i][j] = 0;
                continue;
            }
            if (str1[i] == str2[j]) {
                //문자열이 같다면, 대각선 왼쪽위의 값 +1;
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            }
            else {
                //문자열이 서로 다르면, 왼쪽과 위쪽의 값중 더 큰 것
                if (lcs[i][j - 1] > lcs[i - 1][j]) {
                    lcs[i][j] = lcs[i][j - 1];
                }
                else {
                    lcs[i][j] = lcs[i - 1][j];
                }
            }
        }
    }
    cout << lcs[str1.size() - 1][str2.size() - 1];
    return 0;
}

