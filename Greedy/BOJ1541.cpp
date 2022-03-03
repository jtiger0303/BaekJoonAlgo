#include <iostream>
#include <string>
using namespace std;
string str;
string temp = "";
int sum = 0;
bool isMinus = false; 
int main()
{
    cin >> str;
    for (int i = 0; i <= str.size(); i++) {
        if (str[i] == '+' || str[i] == '-' || str[i] == '\0') {
            if (isMinus) {//+, -, 끝 수이면, temp 저장한 값을 stoi함수를 통해 sum에 저장
                sum -= stoi(temp);
            }
            else {
                sum += stoi(temp);
            }
            temp = "";
            if (str[i] == '-') {
                isMinus = true;
            }
        }
        else {
            temp += str[i];//+, -, 끝 수가 아니면 temp에 저장//
        }
        
    }
    cout << sum << '\n';
    return 0;
}

