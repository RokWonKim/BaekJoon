#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using  namespace std;

int N,M;
long long dp[101][101];
int d[2][2] = {{0,1},{1,0}};
vector<pair<int,int>> arr[101][101];

long long solve(int x, int y) {
    if (x == N && y == M) return 1;

    long long &value = dp[x][y];
    if (value != -1) return value;

    value = 0;
    for (int i = 0; i < 2; i++) {
        int next_x = x + d[i][0];
        int next_y = y + d[i][1];
        bool exist = false;

        if (next_x < 0 || next_x > N || next_y < 0 || next_y > M) continue;
        for (pair<int,int> p : arr[x][y]) {
            if (p.first == next_x && p.second == next_y) {
                exist = true;
                break;
            }
        }

        if (!exist) value += solve(next_x,next_y);
    }

    return value;
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    cin >> N >> M;
    int K;
    cin >> K;
    for (int i = 0; i < K; i++) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        arr[a][b].push_back({c,d});
        arr[c][d].push_back({a,b});
    }

    cout << solve(0,0) << '\n';

    return 0;
}