#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 2*1000*1000*1000;

int N, K;
int arr[1000][3];
int dp[3*1003][1003][1<<3];

int solve(int index, int key, int use) {
    if (key == 0) return 0;
    if (index == N*3) return -INF;

    int &value = dp[index][key][use];
    if (value != -INF) return value;


    value = solve(index+1, key, use >> 1);
    if ( (use & 1) == 1) return value;

    int x = index/3;
    int y = index%3;

    if (x < N-1) {
        int next = use | (1 << 3);
        value = max(value, arr[x][y] + arr[x+1][y] + solve(index+1, key-1, next >> 1) );
    }
    if (y < 2 && (use & (1<<1) ) == 0 ) {
        int next = use | (1 << 1);
        value = max(value, arr[x][y] + arr[x][y+1] + solve(index+2, key-1, next >> 2) );
    }

    return value;
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    fill(&dp[0][0][0], &dp[3*1003-1][1002][1<<3], -INF);

    cin >> N >> K;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < 3; j++)
            cin >> arr[i][j];
        
    cout << solve(0,K,0) << '\n';

    return 0;
}