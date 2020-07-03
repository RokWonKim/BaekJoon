#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int INF = 987654321;

int N;
int sum;
int arr[22][22];
int col_sum[22][22];
//현재 열, 사용한 칸의 수
int dp[22][22][40001];

int solve(int col, int use, int part_sum) {
    int &value = dp[col][use][part_sum];
    if (value != -1) return value;

    if (col == 0) return value = 0;

    value = INF;
    int gap = INF;
    for (int i = use; i <= N; i++) {
        int wait = solve(col-1,i, part_sum+col_sum[i][col-1]) + col_sum[i][col-1];
        int wait_gap = abs( sum-2*(part_sum+wait) );
        if (  gap > wait_gap  ) {
            gap = wait_gap;
            value = wait;
        }
    }

    return value;
}

void trace(int col, int use, int part_sum) {
    if (col == 0) return;

    for (int i = use; i <= N; i++) {
        if ( dp[col-1][i][ part_sum + col_sum[i][col-1] ] == solve(col,use,part_sum) - col_sum[i][col-1] ) {
            trace(col-1, i, part_sum + col_sum[i][col-1]);
            cout << N-i << ' ';
            return;
        }
    }
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            sum += arr[i][j];
        }

    for (int i = N-1; i >= 0; i--)
        for (int j = N-1; j >= 0; j--) {
            col_sum[j][i] = col_sum[j+1][i] + arr[j][i];
        }
    
    cout << abs(sum-2*solve(N,0,0) ) << '\n';
    trace(N,0,0);

    return 0;
}