#include <iostream>
using namespace std;
int t, c;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while (t--) {
        int countq = 0;
        int countd = 0;
        int countn = 0;
        int countp = 0;

        cin >> c;
        while (c) {
            if (c >= 25) {
                countq += c / 25;
                c = c % 25;
            }
            if (c >= 10) {
                countd += c / 10;
                c = c % 10;
            }
            if (c >= 5) {
                countn += c / 5;
                c = c % 5;
            }
            if (c >= 1) {
                countp += c / 1;
                c = c % 1;
            }
        }
       
        cout << countq << ' ' << countd << ' ' << countn << ' ' << countp << '\n';
    }
   
    return 0;
}

