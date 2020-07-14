#include <iostream>

using namespace std;

long long N, M;

int solve(int num, long long a, long long b) {
    if (a > b) swap(a,b);
    if (a*2 <= b || a == b) {
        if (num % 2 == 1) return 2;
        else return 1;
    }

    return solve(num+1, a, b-a);
}

int main(void) {
    ios_base:: sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    if (N > M) swap(N,M);

    if (N*2 <= M || N == M) cout << "win\n";
    else {
        if ( solve(1,N,M) == 2 ) cout << "win\n";
        else cout << "lose\n";
    }

    return 0;
}