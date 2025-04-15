#include <iostream>
using namespace std;
struct Node {
    char cur;
    int left, right;
};
Node nodes[26];
int n;
void preorder(int cur) {
    cout << nodes[cur].cur;
    if (nodes[cur].left) preorder(nodes[cur].left);
    if (nodes[cur].right) preorder(nodes[cur].right);
}
void inorder(int cur) {
    if (nodes[cur].left) inorder(nodes[cur].left);
    cout << nodes[cur].cur;
    if (nodes[cur].right) inorder(nodes[cur].right);
}
void postorder(int cur) {
    if (nodes[cur].left) postorder(nodes[cur].left);
    if (nodes[cur].right) postorder(nodes[cur].right);
    cout << nodes[cur].cur;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    while (n--) {
        char cur, left, right;
        cin >> cur >> left >> right;
        nodes[cur - 'A'].cur = cur;
        if (left != '.') nodes[cur - 'A'].left = left - 'A';
        if (right != '.') nodes[cur - 'A'].right = right - 'A';
    }
    preorder(0);
    cout << '\n';
    inorder(0);
    cout << '\n';
    postorder(0);
}
