#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int INF = 987654321;

int N;
int result[101];
int now[101];
int dp[101][10][10][10][2];

int m(int a) { return (a+10)%10; }

int solve(int index, int x, int y, int z, int dir) {
    if (index == N) return 0;

    int &value = dp[index][x][y][z][dir];

    if (value != -1) return value;
    value = INF;

    if ( m(x+now[index]) == result[index])
        value = min(solve(index+1, y,z,0, 0), solve(index+1, y,z,0,1));

    for (int i = 1; i <= 3; i++) {
        value = min(value, 1+solve(index, m(x+i),y,z,1));
        value = min(value, 1+solve(index, m(x+i),m(y+i),z,1));
        value = min(value, 1+solve(index, m(x+i),m(y+i),m(z+i),1));

        value = min(value, 1+solve(index, m(x-i),y,z,0));
        value = min(value, 1+solve(index, m(x-i),m(y-i),z,0));
        value = min(value, 1+solve(index, m(x-i),m(y-i),m(z-i),0));
    }

    return value;
}

int main(void) {

    memset(dp, -1, sizeof(dp));
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%1d", &now[i]);
    for (int i = 0; i < N; i++) scanf("%1d", &result[i]);

    printf("%d\n", solve(0,0,0,0,0));

    return 0;
}