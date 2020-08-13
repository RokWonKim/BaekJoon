#include <iostream>
#include <vector>
#include <cstring>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        long long r,g,b,w;
        cin >> r >> g >> b >> w;
        long long m = min(r,min(g,b));

        int cnt = 0;
        int w_cnt = 0;
        if (r % 2 == 1) cnt++;
        if ( g % 2 == 1) cnt++;
        if (b % 2 == 1) cnt++;
        if (w % 2 == 1) cnt++;

        if (m != 0) {
            if ( (r-1) % 2 == 1) w_cnt++;
            if ( (g-1) % 2 == 1) w_cnt++;
            if ( (b-1) % 2 == 1) w_cnt++;
            if ( (w+3) % 2 == 1) w_cnt++;
        }
        
        
        if (r+g+b+w == 0) cout << "Yes\n";
        else if (cnt <= 1) cout << "Yes\n";
        else if (m != 0 && w_cnt <= 1) cout << "Yes\n";
        else cout << "No\n";

    }
    
   return 0;
}