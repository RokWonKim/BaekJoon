#include <iostream>
#include <cstring>

using namespace std;

int N, M;
long long dp[21][21];

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

long long solve(int boom, int key) {
    if (key == 0) return 1;
    if (boom == 0) return 0;

    long long &value = dp[boom][key];
    if(value != -1) return value;

    value = solve(boom-1, key-1) + (key-1)*solve(boom, key-1);

    return value;
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));
    cin >> N >> M;

    long long top = solve(M,N);
    long long bottom = solve(N,N);
    long long mod = gcd(top, bottom);

    cout << top/mod << '/' << bottom/mod << '\n';
    return 0;
}