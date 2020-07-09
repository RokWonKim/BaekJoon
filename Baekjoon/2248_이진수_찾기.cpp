#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int N,L;
long long I;
long long dp[33][33];
string answer;

long long combination(int n, int r) {
    if (n == r || r == 0) return dp[n][r] = 1;

    long long &value = dp[n][r];
    if(value != -1) return value;

    return value = combination(n-1,r-1) + combination(n-1, r);
}

void solve(int now_n, int now_l, long long now_i) {
    if (now_n == 0) return;
    if (now_l == 0) {
        for(int i = 0; i < now_n; i++)
            answer += '0';
        return;
    }

    long long p = 0;
    for (int i = 0; i <= now_l && i <= now_n-1; i++) p += combination(now_n-1, i);

    if (p >= now_i) {
        answer += '0';
        solve(now_n-1, now_l, now_i);
    }
    else {
        answer += '1';
        solve(now_n-1, now_l-1, now_i-p);
    }

}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(dp,-1,sizeof(dp));

    cin >> N >> L >> I;

    dp[0][0] = 1;
    solve(N,L,I);
    cout << answer;

    return 0;
}