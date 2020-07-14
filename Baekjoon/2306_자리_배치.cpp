#include <iostream>
#include <cstring>

using namespace std;

int N, K;
// 자신의 전 자리가 채워졌는지, 지금 자리가 채워졌는지
int dp[42][2][2][2];

int solve(int num, int pre, int now, int use) {
    if (num == N+1) {
        if(now != 1) return 1;
        else return 0;
    }

    int &value = dp[num][pre][now][use];
    if (value != -1) return value;

    value = 0;
    if (num == K)
        value += solve(num+1,1,0,use);
    else if (num == 1) {
        value += solve(num+1, 1, 0, 0);
        if (num+1 != K)
            value += solve(num+1, 0, 1, 0);
        value += solve(num+1, 0, 0, 1);
    }
    else {
        if (pre == 0)
            value += solve(num+1, now, 0, use);
        if (now == 0)
            value += solve(num+1, 1, 0, use);
        if (num+1 != K)
            value += solve(num+1, now, 1, use);
        if (use == 0)
            value += solve(num+1, now, 0, 1);
    }

    return value;
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));
    
    cin >> N >> K;
    cout << solve(1,0,0,0) << '\n';

    return 0;
}