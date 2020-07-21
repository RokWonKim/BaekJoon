#include <iostream>

using namespace std;

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        long long l,r,m;
        cin >> l >> r >> m;

        long long a = r;
        while (a >= l) {
            long long p1 = m/a;
            long long p2 = p1+1;

            if (p1) {
                if (m%a <= r-l) {
                    cout << a << ' ' << r << ' ' << r-(m%a)<<'\n';
                    break;
                }
            }
            else {
                if (a - m <= r-l) {
                    cout << a << ' ' << r-(a - m) << ' ' << r<<'\n';
                    break;
                }
            }            
            
            if (a*p2-m  <= r-l ) {
                cout << a << ' ' << r-(a*p2-m) << ' ' << r<<'\n';
                break;

            }
            a--;

        }

    }

    return 0;

}