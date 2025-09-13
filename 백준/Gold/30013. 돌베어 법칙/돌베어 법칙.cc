#include <iostream>
using namespace std;
int n;
string s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> s;

    int answer = n;
    for (int k = 1; k <= n; k++) {
        int cnt = 0;
        for (int r = 0; r < k; r++) {
            bool prevHash = false;
            for (int j = r; j < n; j += k) {
                if (s[j] == '#') {
                    if (!prevHash) ++cnt;   // 새 연속 구간 시작
                    prevHash = true;
                }
                else {
                    prevHash = false;       // 연속 끊김
                }
            }
        }
        answer = min(answer, cnt);
    }
    cout << answer << '\n';
    return 0;
}

