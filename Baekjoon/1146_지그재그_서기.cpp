#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1*1000*1000;

int N;
int dp[101][101];

int solve(int left, int right) {
    if (left == 0 && right == 0) return 1;

    int &value = dp[left][right];
    if (value != -1) return value;

    value = 0;
    for (int i = 0; i < right; i++)
        value = (value + solve(right-1-i, left+i)) % MOD;
        
    return value;
}

int main(void) {
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    memset(dp , -1, sizeof(dp));
    cin >> N;
    int ans = 0;

    for (int i = 0; i < N; i++)
        ans = (ans + solve(i, N-1-i)) % MOD;

    if (N == 1) cout << 1;
    else cout << (ans*2)%MOD << '\n';

    return 0;
} 