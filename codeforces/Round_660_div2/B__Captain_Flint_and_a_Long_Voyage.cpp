#include <iostream>
#include <cstring>

using namespace std;

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        int num = (3+n)/4;

        for (int i = n; i > 0; i--) {
            if (i <= num) cout << 8;
            else cout << 9;
        }
        cout << '\n';
    }

    return 0;
}