#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1000;

int N;
int dist[501];
int jump[501];
int go[501];
int dp[501][501];

int solve(int went, int came) {
    if (went == N-1) return 0;
    if (came == N-1) {
        if (dist[went]+jump[went] >= dist[came]) return 1;
        else return 0;
    }

    int &value = dp[went][came];
    if (value != -1) return value;

    value = 0;
    int next = max(went, came) + 1;
    for (int i = next; i < N; i++) {
        if (dist[went] + jump[went] >= dist[i])
            value = (value + solve(i, came)) % MOD; 
        if (dist[i] - jump[i] <= dist[came] && go[i] == 1)
            value = (value + solve(went ,i)) % MOD;
    }
    return value;
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> dist[i] >> jump[i] >> go[i];
    
    cout << solve(0,0) << '\n';
    return 0;
}