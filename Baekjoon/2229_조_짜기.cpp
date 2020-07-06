#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int arr[1001];
int dp[1001];
int seg[1001][1001];
int N;

int solve(int start) {
    if (start == N) return 0;

    int &value = dp[start];
    if (value != -1) return value;

    for (int i = start; i < N; i++)
        value = max(value, seg[start][i] + solve(i+1) );

    return value;
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 0; i < N; i++) {
        int max_e = arr[i];
        int min_e = arr[i];
        for (int j = i; j < N; j++) {
            max_e = max(arr[j],max_e);
            min_e = min(min_e, arr[j]);
            seg[i][j] = max_e-min_e;
        }
    }

    cout << solve(0);

    return 0;
}