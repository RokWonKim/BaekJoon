#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <string>

using namespace std;

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int N;
    
    int two = 0;
    int one = 0;
    int v = 0;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if ( a % 2 == 1) {
            one++;
            v += a-1;
        }
        else v += a;
        
    }
    two = v/2;


    if (N == 1) cout << "YES\n";
    else {
        if (one == two) cout << "YES\n";
        else if (one > two) cout << "NO\n"; 
        else {
            if ((two-one) % 3 == 0 ) cout << "YES\n";
            else cout << "NO\n";
        }
        
    }

    return 0;
}