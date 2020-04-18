#include<iostream>

using namespace std;

const int m = 1000000000;
int N;
// N번째, 지금 나의 수, 0~9를 다 갔는지
long long dp[101][10][1 << 10];

int main(void) {
    
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    long long ans = 0;
    
    for (int j = 1; j <=9; j++)
        dp[1][j][1<<j] = 1;
    
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k < (1<<10); k++) {
                if (j < 9)
                    dp[i][j][ k | (1<<j)] += (dp[i-1][j+1][k] % m);
                if (j > 0)
                    dp[i][j][ k | (1<<j) ] += (dp[i-1][j-1][k] % m);
            }
        }
    }
    
    
    for (int i = 0; i <= 9; i++)
        ans = (ans + dp[N][i][ (1<<10)-1 ])%m;
    
    cout << ans << '\n';
    return 0;
}
