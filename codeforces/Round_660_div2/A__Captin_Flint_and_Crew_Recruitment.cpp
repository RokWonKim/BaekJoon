#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        if (N <= 30) cout << "NO\n";
        else if(N == 36) {
            cout << "YES\n";
            cout << 5 << ' ' << 6 << ' ' << 10 << ' ' << 15 << '\n';
        }
        else if (N == 44) {
            cout << "YES\n";
            cout << 6 << ' ' << 7 << ' ' << 10 << ' ' << 21 << '\n';
        }
        else if (N== 40) {
            cout << "YES\n";
            cout << 10 << ' ' << 14 << ' ' << 15 << ' ' << 1 << '\n';
        }
        else {
            cout << "YES\n";
            cout << 6 << ' ' << 10 << ' ' << 14 << ' ' << N-30 << '\n';
        }
    }