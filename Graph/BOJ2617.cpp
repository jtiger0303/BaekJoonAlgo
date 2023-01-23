#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, m;
int a, b, marble[101][101];
vector<int> v1[101];
vector<int> v2[101];
int visited[101];
int cnt = 0;
int rcnt = 0;
void bfs(int here) {
    //정방향 bfs//
    queue<int> q;
    visited[here] = 1;
    q.push(here);

    while (q.size()) {
        int here = q.front();
        q.pop();

        for (int there : v1[here]) {
            if (visited[there]) continue;
            visited[there] = visited[here] + 1;
            q.push(there);
            cnt++;
        }
    }
}
void rbfs(int here) {
    //역방향 bfs//
    queue<int> q;
    visited[here] = 1;
    q.push(here);

    while (q.size()) {
        int here = q.front();
        q.pop();

        for (int there : v2[here]) {
            if (visited[there]) continue;
            visited[there] = visited[here] + 1;
            q.push(there);
            rcnt++;
        }
    }
}
void clear() {
    //초기화 함수
    cnt = 0;
    rcnt = 0;
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    int ans = (n + 1) / 2;
    int result = 0;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v1[a].push_back(b);
        v2[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        clear();
        bfs(i);
        rbfs(i);
        
        if (cnt >= ans || rcnt >= ans) result++;
    }
    cout << result << '\n';
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
