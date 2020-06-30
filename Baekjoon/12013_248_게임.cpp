#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int answer = 0;
int dp[249][249];
int arr[249];

int solve(int start, int end) {
    if (start == end) return arr[start];

    int &value = dp[start][end];
    if (value != -1) return value;

    value = -INF;
    for (int i = start; i < end; i++) {
        if (solve(start,i) == solve(i+1, end)) {
            value = max(solve(start,i)+1,value);
            answer = max(value, answer);
        }
    }

    return value;
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));
    int N;
    cin >> N;

    for (int i = 0 ; i < N; i++) {
        cin >> arr[i];
        answer = max(answer ,arr[i]);
    }

    solve(0, N-1);

    cout << answer;

    return 0;
}