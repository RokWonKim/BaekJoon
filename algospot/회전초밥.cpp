#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

const int MOD = 201;

int n,m;
int prefer[21];
int price[21];
// 최대값이 20000임 고로 나머지를 써서 메모리를 줄일 수도 있음
// 줄여야 함
int dp[201];

//재귀가 너무 깊어짐
/*
int solve(int max_price) {

    int &value = dp[max_price];
    if (value != -1) return value;
    cout << 1;

    value = 0;
    for (int i = 0; i < n; i++) {
        if ( max_price + price[i] <= m) {
            value = max(value, solve(max_price + price[i]) + prefer[i] );
        }
    }
        
    return value;
}
*/

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        memset(dp, 0, sizeof(dp));
        cin >> n >> m;
        m /= 100;
        for (int i = 0; i < n; i++) {
            int value1,value2;
            cin >> value1 >> value2;
            price[i] = value1/100;
            prefer[i] = value2;
        }

        int ans = 0;

        for (int i = 0; i <= m; i++) {
            int candid = 0;
            for (int j = 0; j < n; j++) {
                if(i - price[j] >= 0)
                    candid = max(dp[ (i-price[j]) % MOD ] + prefer[j], candid );
                dp[i%MOD] = candid;
                ans = max(dp[i%MOD], ans);
            }
        }
        cout << ans <<'\n';
    }

    return 0;
}