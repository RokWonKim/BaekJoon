#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1*1000*1000;

int dp[201][4001];
int num[201];

int solve(int num_now, int select) {
    if (select == 0) return 1;
    if (num_now == 0) return 0;

    int &value = dp[num_now][select];
    if (value != -1) return value;

    value = 0;
    for (int i = 0; i <= num[num_now]; i++) {
        if (select - i >= 0)
            value = (value + solve(num_now-1, select-i)) % MOD;
    }

    return value;
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp) );

    int T,A,S,B;
    int answer = 0;
    cin >> T >> A >> S >> B;

    for (int i = 0; i < A; i++) {
        int v;
        cin >> v;
        num[v]++;
    }

    for (int i = S; i <= B; i++)
        answer = (answer + solve(T,i)) % MOD;
    
    cout << answer << '\n';

    return 0;
}