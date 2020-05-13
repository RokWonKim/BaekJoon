#include<iostream>
#include<vector>

using namespace std;

const int INF = -100000000;

int arr[51];
//왼쪽에 몇, 우측에 몇
int dp[51][51];

int solve(int left, int right) {
    if (left > right) return 0;
    
    int &value = dp[left][right];
    if (value != INF) return value;

    if (right-left+1 >= 2) {
        value = max(value, -solve(left+2, right));
        value = max(value, -solve(left, right-2));
    }
    value = max(value, arr[left] -solve(left+1, right));
    value = max(value, arr[right] -solve(left, right-1));

    return value;
}


int main(void) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;

        for (int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                dp[i][j] = INF;

        for(int i = 0; i < N; i++)
            cin >> arr[i];

        cout << solve(0, N-1) << '\n';
    }

    return 0;
}