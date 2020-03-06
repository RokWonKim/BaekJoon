#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

int arr[501][501];
int dp[501][501];
int N;
int m[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };

int solve(int a, int b) {


    if ( dp[a][b] != -1)
        return dp[a][b];
    
    dp[a][b] = 0;
    for(int i = 0; i < 4; i++) {
        int dx = m[i][0] + a;
        int dy = m[i][1] + b;

        if (dx >= N || dy >= N || dx < 0 || dy < 0 )
            continue;

        if (arr[a][b] < arr[dx][dy])
            dp[a][b] = max( dp[a][b], solve(dx,dy)+1 );
    }
    
    return dp[a][b];
}

int main(void) {

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    cin >> N;

    int ans = 0;

    for (int i = 0; i< N; i++)
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];


    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            ans = max(solve(i,j), ans);
    
    cout << ans+1;

    return 0;
}