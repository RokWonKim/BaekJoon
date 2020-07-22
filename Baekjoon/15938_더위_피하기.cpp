#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

const int MOD = 1e9 + 7;
int d[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int dp[420][420][203];
int arr[420][420];

int x, y;
int t;
int hx, hy;

int solve(int a, int b, int time) {
    if (time > t) return 0;
    if (a==hx && b==hy) return 1;

    int &value = dp[a][b][time];
    if (value != -1) return value;

    value = 0;
    for (int i = 0; i < 4; i++) {
        int next_a = a + d[i][0];
        int next_b = b + d[i][1];
        if(next_a < 0 || next_a > 410 || next_b < 0 || next_b > 410) continue;
        if (arr[next_a][next_b] == 1) continue;

        value = (value+solve(next_a,next_b,time+1)) % MOD;
    }
    return value;

}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    
    cin >> x >> y;
    cin >> t;
    cin >> hx >> hy;

    int start_x = 210;
    int start_y = 210;

    int diff_x = start_x - x;
    int diff_y = start_y - y;
    x = 210;
    y = 210;
    hx += diff_x;
    hy += diff_y;

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a,b;
        cin >> a >> b;
        a += diff_x;
        b += diff_y;

        if (a < 0 || a > 410 || b < 0 || b > 410) continue;
        arr[a][b] = 1;
    }

    if (hx < 0 || hx > 410 || hx < 0 || hy > 410) {
        cout << 0 << '\n';
        return 0;
    }

    cout << solve(210, 210, 0) << '\n';

    return 0;
}