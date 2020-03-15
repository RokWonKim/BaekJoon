#include<iostream>

using namespace std;

int main(void) {

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int N;
    int ans = 1;
    cin >> N;

    int arr[N];
    int dp[N];

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        dp[i] = 1;
    }

    for (int i = 1; i < N; i++)
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j]){
                dp[i] = max(dp[j]+1, dp[i]);
                ans = max(dp[i],ans);
            }

    cout << ans;

    return 0;
}