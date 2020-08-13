#include <iostream>
#include <vector>
#include <cstring>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

const int INF = 10000;
int n,m;
int arr[201];
int b[201];
int dp[201][1 << 10];

int solve(int start, int now) {
    if (start == n) return now;

    int &value = dp[start][now];
    if (value != -1) return value;

    value = INF;
    for (int i = 0; i < m; i++)
        value = min(value,  (solve(start+1,  (arr[start] & b[i]) | now ) ) );

    return value;
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    cout << solve(0, 0) << '\n'; 

   return 0;
}