// BOJ2852.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#define prev kundo1
using namespace std;
int n, o, A, B, asum, bsum;
string s, prev;
string print(int a) {
    string d = "00" + to_string(a / 60);
    string e = "00" + to_string(a % 60);
    return d.substr(d.size() - 2, 2) + ":" + e.substr(e.size() - 2, 2);
}
int changeToInt(string a) {
    return atoi(a.substr(0, 2).c_str()) * 60 + atoi(a.substr(3, 2).c_str());
}
void go(int& sum, string s) {
    sum += (changeToInt(s) - changeToInt(prev));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> o >> s;
        if (A > B) go(asum, s);
        else if (A < B) go(bsum, s);
        o == 1 ? A++ : B++;
        prev = s;
    }
    if (A > B) go(asum, "48:00");
    else if (A < B) go(bsum, "48:00");
    cout << print(asum) << '\n';
    cout << print(bsum) << '\n';

}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
