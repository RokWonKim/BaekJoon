#include<iostream>
#include<string.h>

using namespace std;

int N, K;

int dp[2001][2];
int arr[2001];

int main(void) {

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    memset(dp, 0, sizeof(dp));

    cin >> N;

    int ans = 1;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        dp[i][0] = 1;
        dp[i][1] = 1;
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {

            if (arr[i] > arr[j] )
                dp[i][0] = max(dp[i][0], dp[j][0] + 1);
                
            if (arr[i] < arr[j] )
                dp[i][1] = max(dp[i][1], max( dp[j][0]+1, dp[j][1]+1 ));

            ans = max(ans, max(dp[i][0], dp[i][1]));
        }
    }

    cout << ans;

    return 0;
}