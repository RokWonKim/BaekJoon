#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int a[51];
int b[51];

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        int up = *min_element(a, a+n);
        int bottom = *min_element(b, b+n);

        long long answer = 0;

        for (int i = 0; i < n; i++) {
            int da = a[i]-up;
            int db = b[i]-bottom;
            answer += (long long)max(da,db);
        }

        cout << answer <<'\n';
    }

    return 0;
}