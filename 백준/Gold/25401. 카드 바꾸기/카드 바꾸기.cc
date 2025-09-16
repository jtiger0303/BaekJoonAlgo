#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    vector<int> card(n);
    int answer = 987654321;

    for (int i = 0; i < n; i++) {
        cin >> card[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cnt = 0;
            if (i == j || ((card[i] - card[j]) % (i - j)) == 0) {
                int gap;
                if (i == j) gap = 0;
                else gap = ((card[i] - card[j]) / (i - j));

                vector<int> tmp = card;

                for (int k = i + 1; k < n; k++) {
                    // 오른쪽을 등차 수열로 정렬
                    int value = gap + tmp[k - 1];
                    if (value != card[k]) cnt++;
                    tmp[k] = value;
                }

                for (int k = i - 1; k > -1; k--) {
                    // 왼쪽을 등차 수열로 정렬
                    int value = tmp[k + 1] - gap;
                    if (value != card[k]) cnt++;
                    tmp[k] = value;
                }
                answer = min(answer, cnt);
            }
        }
    }
    cout << answer << '\n';
    return 0;
}

