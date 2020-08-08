#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        cout << n/2+1 << '\n';
    }

    return 0;
}