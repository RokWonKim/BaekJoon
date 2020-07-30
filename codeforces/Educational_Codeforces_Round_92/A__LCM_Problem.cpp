#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int l,r;
        cin >> l >> r;
        int x,y;
        x = y = 0;
        if (r % 2 != 0) r--;
        y = r;
        if (y/2 >= l) cout << y/2 << ' ' << y << '\n';
        else cout << -1 << ' ' << -1 << '\n';
    }

    return 0;
}