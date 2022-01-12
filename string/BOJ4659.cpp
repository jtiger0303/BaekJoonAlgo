// BOJ4659.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string.h>
using namespace std;
#define sz(x) ((int)(x).size())
#define f first
#define s second
typedef unsigned long long ll;
const int INF = 987654321;
string s;
int cnt[30], lcnt, vcnt;
bool isVowel(int idx) {//모음인지 판단
    return (idx == 0 || idx == 4 || idx == 8 || idx == 14 || idx == 20);
}
int main()
{
    while (true) {
        cin >> s;
        if (s == "end") break;
        memset(cnt, 0, sizeof(cnt));
        lcnt = vcnt = 0;
        bool flag = 0;
        for (int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';
            cnt[idx]++;
            if (isVowel(idx)) {
                lcnt++;//연속되는 모음
                vcnt = 0;
            }
            else {
                vcnt++;
                lcnt = 0;
            }
            if (vcnt == 3 || lcnt == 3) flag = 1;
            if (i >= 1 && (s[i - 1] == s[i]) && (idx != 4 && idx != 14)) {
                flag = 1;
            }



        }
        if (!cnt[0] && !cnt[4] && !cnt[8] && !cnt[14] && !cnt[20]) flag = 1;
        if (flag) {
            cout << "<" << s << ">" << " is not acceptable.\n";
        }
        else {
            cout << "<" << s << ">" << " is acceptable.\n";
        }
    }
    return 0;
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
