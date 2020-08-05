#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 201;

int N;
// start 부터 num개가 남고 part_sum의 차이가 날때 = silver가 먹은 양
int dp[1001][1001][201];
int arr[1001];

int solve(int start, int num, int part_sum) {
    if (num == 0) return part_sum;

    int p = part_sum + 100;
    int &value = dp[start][num][p];
    if (value != -INF) return value;

    int last = (start+num-1) % N;
    int next = (start+1)%N;
    if (part_sum <= 0) {
        value = max(solve(next,num-1, part_sum+arr[start]),
                    solve(start,num-1, part_sum+arr[last]));
    }
    else {
        value = min(solve(next,num-1, part_sum-arr[start]),
                    solve(start,num-1, part_sum-arr[last]));
    }

    return value;
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    fill( &dp[0][0][0], &dp[1000][1000][201], -INF );

    int sum = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    int max_diff = -101;
    for (int i = 0; i < N; i++) {
        max_diff = max(max_diff, solve( (i+1)%N, N-1, arr[i]) );
    }
    
    int answer = sum/2 + max_diff/2;
    if (max_diff %2 == 1) answer++;

    cout << answer << '\n';

    return 0;
}