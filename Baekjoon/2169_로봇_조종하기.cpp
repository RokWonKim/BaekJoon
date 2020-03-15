#include<iostream>

using namespace std;

const int INF = -210000000;

int N, M;
int arr[1002][1002];
int dp[1002][1002][3];

int coor[3][2] = { {0,1}, {0,-1}, {1,0} };

int solve(int x, int y, int where_not, int where_me) {

    if (x == N-1 && y == M-1)
        return arr[N-1][M-1];

    int  &value = dp[x][y][where_me];
    if (value != INF)
        return value;

    for(int i = 0; i < 3; i++) {
        if (where_not == i) continue;

        int new_x = x + coor[i][0];
        int new_y = y + coor[i][1];
        if (new_x < 0 || new_x >= N || new_y < 0 || new_y >= M)
            continue;

        if (i == 0)
            value = max(value, solve(new_x,new_y, 1,i) + arr[x][y] );
        else if (i == 1)
            value = max(value, solve(new_x,new_y, 0,i) + arr[x][y] );
        else 
            value = max(value, solve(new_x,new_y, -1,i) + arr[x][y] );
    }
    return value;
}

int main(void) {

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];

            for (int z = 0; z < 3; z++)
                dp[i][j][z] = INF;
        }
    }

    cout << solve(0,0,-1,0);

    return 0;
}