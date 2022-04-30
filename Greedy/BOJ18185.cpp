#include <iostream>
#include <algorithm>
using namespace std;
int factory[10004];
int n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int count, count2;
    int answer = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> factory[i];
    }

    for (int i = 1; i <= n; i++) {
        if (factory[i + 1] > factory[i + 2]) {
            //3개 불가능//
            count = min(factory[i], factory[i + 1] - factory[i + 2]);
            answer += 5 * count;

            factory[i] -= count;
            factory[i + 1] -= count;

            count2 = min(factory[i], min(factory[i + 1], factory[i + 2]));
            answer += 7 * count2;

            factory[i] -= count2;
            factory[i + 1] -= count2;
            factory[i + 2] -= count2;


        }
        else {
            //3개 가능//
            count = min(factory[i], min(factory[i + 1], factory[i + 2]));
            answer += 7 * count;

            factory[i] -= count;
            factory[i+1] -= count;
            factory[i + 2] -= count;

            count2 = min(factory[i], factory[i + 1]);
            answer += 5 * count2;
            factory[i] -= count2;
            factory[i + 1] -= count2;
        }
        answer += 3 * factory[i];
        factory[i] = 0;
    }
    cout << answer << '\n';
    return 0;
}

