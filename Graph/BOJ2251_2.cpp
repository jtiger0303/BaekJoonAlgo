#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int visited[201][201][201];
int A, B, C;
queue<pair<pair<int, int>, int>> q; //A, B, C
vector<int> bfs() {
    q.push(make_pair(make_pair(0, 0), C));
    vector<int> result;
    while (q.size()) {
        int a = q.front().first.first;
        int b = q.front().first.second;
        int c = q.front().second;
        q.pop();

        if (visited[a][b][c]) continue;
        visited[a][b][c] = 1;
        if (a == 0) result.push_back(c);
        //A->B
        if (a + b > B) {
            //넘치면 안됨
            q.push(make_pair(make_pair(a + b - B, B), c));
        }
        else {
            q.push(make_pair(make_pair(0, a + b), c));
        }
        //A->C
        if (a + c > C) {
            q.push(make_pair(make_pair(a + c - C, b), C));
        }
        else {
            q.push(make_pair(make_pair(0, b), a + c));
        }
        //B->A
        if (b + a > A) {
            q.push(make_pair(make_pair(A, b + a - A), c));
        }
        else {
            q.push(make_pair(make_pair(b + a, 0), c));
        }
        //B-<C
        if (b + c > C) {
            q.push(make_pair(make_pair(a, b + c - C), C));
        }
        else {
            q.push(make_pair(make_pair(a, 0), b + c));
        }
        //C->A
        if (c + a > A) {
            q.push(make_pair(make_pair(A, b), c + a - A));
        }
        else {
            q.push(make_pair(make_pair(c + a, b), 0));
        }
        //C->B
        if (c + b > B) {
            q.push(make_pair(make_pair(a, B), c + b - B));
        }
        else {
            q.push(make_pair(make_pair(a, c + b), 0));
        }


    }
    return result;
}
int main()
{
    cin >> A >> B >> C;
    vector<int> result = bfs();
    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';
    }
    return 0;
}

