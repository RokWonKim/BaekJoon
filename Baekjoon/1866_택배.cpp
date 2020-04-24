#include<iostream>
#include<algorithm>

using namespace std;

int arr[5001];
int dp[5001];

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    int N,T,H;
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    cin >> T >> H;
    sort(arr+1, arr+N+1);
    
    
    for (int i = 1; i <= N; i++) {
        dp[i] = dp[i-1] + arr[i]*T;
        int value = H;
        for (int j = i; j >= 0; j--) {
            value += T * (arr[(i+j+1)/2]-arr[j]);
            dp[i] = min(dp[i], dp[j-1] + value);
        }
    }
    
    cout << dp[N];
    
    return 0;
}
