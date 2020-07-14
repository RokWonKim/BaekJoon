#include <iostream>
#include <cstring>

using namespace std;

int N,M,C;
int arr[14];
int dp[10][21][1<<14];

int solve(int bag, int lim, int use_j) {

    int &value = dp[bag][lim][use_j];
    if (value != -1) return value;

    value = 0;
    for (int i = 0; i < N; i++) {
        if ( (use_j & (1 << i)) == 0 ) {
            if (C < arr[i]) continue;
            if (lim + arr[i] <= C)
                value = max(value,solve(bag, lim+arr[i], use_j | (1<<i))+1 );
            else {
                if (bag+1 == M) continue;
                value = max(value, solve(bag+1, arr[i], use_j | (1<<i))+1 );
            }
        }
    }

    return value;
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    cin >> N >> M >> C;
    for (int i = 0; i < N; i++) cin >> arr[i];
    
    cout << solve(0,0,0) << '\n';

    return 0;
}