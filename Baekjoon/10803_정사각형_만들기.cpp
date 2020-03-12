#include<iostream>
#include<string.h>

using namespace std;

const int INF = 210000000;

int n, m;
int dp[10002][102];

int solve(int raw, int col) {
    int &value = dp[raw][col];

    if (raw == col)
        return value = 1;
    if (value != -1)
        return value;

    value = INF;
    if (raw >= col*3)
        value = min(value, solve(raw-col, col)+1);
    else if(col >= raw*3)
        value = min(value, solve(raw, col-raw)+1);
    else {
        for (int i = 1; i <= raw/2; i++)
            value = min(value, solve(raw-i, col)+solve(i, col) );
        for (int i = 1; i <= col/2; i++)
            value = min(value, solve(raw,col-i)+solve(raw,i));
    }

    return value;
}

int main(void) {

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    cin >> n >> m;
    cout << solve(n, m);

    return 0;
}