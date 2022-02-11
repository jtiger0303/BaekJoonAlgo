#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;
int T, N, X;
string p, order;
int main()
{
    cin >> T;
    for (int t = 0; t < T; t++) {
        deque<int> D;
        cin >> p >> N >> order;
        X = 0;
        
        for (char c : order) {
            if (c == '[' || c == ']') continue;
            //숫자가 나오면 현재수*10한 뒤 더함//
            if (c >= '0' && c <= '9') X = X * 10 + c - '0';
            else {//아닐 경우 현재 수를 덱에 넣음
                if (X > 0) D.push_back(X);
                X = 0;
            }
        }
        if (X > 0) D.push_back(X);
        bool error = false, rev = false;
        for (char a : p) {
            if (a == 'R') rev = !rev;
            else {
                //비어있는데 제거하려 하면 에러
                if (D.empty()) {
                    error = true;
                    break;
                }
                if (rev) D.pop_back();
                else D.pop_front();
            }
        }
        if (error) cout << "error" << '\n';
        //아닐 경우 덱의 원소를 하나하나 출력
        else {
            cout << '[';
            //덱이 뒤짐힌 상태면 진짜로 뒤집어준다.
            if (rev) reverse(D.begin(), D.end());
            for (int i = 0; i < D.size(); i++) {
                cout << D[i];
                if (i < D.size() - 1) {
                    cout << ", ";
                }
                ;
            }
            cout << "]\n";
        }
    }
   
}

