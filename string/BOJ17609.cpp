#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int t;
string s;
//check=0: 회문 판단, check=1: 유사회문 판단
int palindrome(string str, int check) {
    int left, right;
    left = 0;
    right = str.size() - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            if (check == 0) {
                //유사회문인지 판단
                int len = right - left;
                if (palindrome(str.substr(left + 1, len), 1) == 0 || palindrome(str.substr(left, len), 1) == 0) {
                    return 1; //유사회문일 때
                }
                else return 2;
            }
            else return 2;
        }
        left++;
        right--;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> s;
        cout << palindrome(s, 0) << '\n';
    }
    return 0;
}

