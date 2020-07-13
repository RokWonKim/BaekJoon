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
        int N;
        cin >> N;
        for (int i = 0; i < N; i++)
            cout << 1 << ' ';

        cout << '\n';
    }

    return 0;
}