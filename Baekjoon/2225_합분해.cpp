#include<iostream>

using namespace std;

int N, K;

int dp[201][201];

int main(void) {

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    for (int i = 1; i <= K; i++) {
        for (int j = 1; j <= N; j++) {
            int sum = 0;
            for (int z = 0; z <= j; z++)
                sum = (sum+dp[i-1][z])%1000000000;
            dp[i][j] = sum+1;
        }
    }

    cout << dp[K][N];

    return 0;
}