#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int N, i;
        cin >> N;
        for (i = 2; i < 100000; i++)
            if ( N % i == 0) break;

        if (i == 100000)
            cout << 1 << ' ' << N-1 <<'\n';
        else
            cout << N/i << ' ' << N - (N/i) << '\n';

    }

    return 0;
}