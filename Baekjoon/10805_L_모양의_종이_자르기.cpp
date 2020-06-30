#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

const int INF = 987654321;

int dp[51][51][51][51];
int a,b,c,d;

int solve(int h1, int w1, int h2, int w2) {
    if (h1 == w1 && h2 == 0 && w2 == 0) return 1;

    int &value = dp[h1][w1][h2][w2];
    if (value != -1) return value;

    value = INF;
    //수평으로 자르기
    for (int i = 1; i < h1; i++) {
        if ( i < h1-h2) value = min(value, solve(i,w1,0,0) + solve(h1-i,w1,h2,w2));
        else if ( i == h1-h2 ) value = min(value, solve(i,w1,0,0) + solve(h1-i,w1-w2,0,0));
        else value = min(value,solve(h1-i,w1-w2,0,0)+solve(i,w1,i-(h1-h2),w2));
    }

    //수직으로 자르기
    for (int i = 1; i < w1; i++) {
        if ( i < w1-w2) value = min(value, solve(h1, w1-i, h2, w2)+solve(h1,i,0,0));
        else if ( i == w1-w2) value = min(value, solve(h1,i,0,0) + solve(h1-h2,w1-i,0,0));
        else value = min(value, solve(h1-h2, w1-i, 0,0)+solve(h1, i, h2, i-(w1-w2)));
    }

    return value;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(dp,-1,sizeof(dp));

    cin >> a >> b >> c >> d;
    cout << solve(a,b,c,d) << '\n';

    return 0;
}
