#include<iostream>
#include<string.h>

using namespace std;

int N;
int left_card[2001];
int right_card[2001];
int dp[2001][2001];

int solve(int left, int right){

    if (left > N || right > N)
        return 0;

    if (dp[left][right] != -1)
        return dp[left][right];

    if ( left_card[left] > right_card[right])
        dp[left][right] = right_card[right]+ solve(left,right+1);
    else
        dp[left][right] = max( solve(left+1,right), solve(left+1,right+1) );


    return dp[left][right];
}

int main(void) {

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> left_card[i];
    for (int i = 1; i <= N; i++)
        cin >> right_card[i];

    cout << solve(1,1);

    return 0;
}