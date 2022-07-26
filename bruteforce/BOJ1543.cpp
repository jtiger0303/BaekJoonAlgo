#include <iostream>
#include <string>
using namespace std;
string input, output;
int cnt = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    getline(cin, output);
    getline(cin, input);
    
    for (int i = 0; i < output.length(); i++) {
        bool flag=true;
        for (int j = 0; j < input.length(); j++) {
            if (output[i + j] != input[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cnt++;
            i += input.length() - 1;
        }

    }
    cout << cnt;
}

