#include <iostream>
#include <vector>
#include <cstring>
#include <set>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cout << i << ' ';
        cout << '\n';
    }
   return 0;
}