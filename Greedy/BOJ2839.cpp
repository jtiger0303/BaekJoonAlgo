#include <iostream>
using namespace std;
int n;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int count5, count3;
	cin >> n;
	
	count5 = n / 5;
	while (true) {
		if (count5 < 0) {
			cout << "-1" << '\n';
			return 0;
		}
		if ((n - (5 * count5)) % 3 == 0) {
			count3 = (n - (5 * count5)) / 3;
			break;
		}
		count5--;//아니면 5kg짜리를 줄여가면서 봉지 구하기
	}
	cout << count5 + count3 << '\n';
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
