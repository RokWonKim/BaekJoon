#include<iostream>
#include<string>

using namespace std;

const int INF = 2100000000;

int N;
int min_machine;

int arr[16][16];
int dp[1 << 16];

int solve(int factory_on, int flag) {

    if (flag >= min_machine)
        return 0;

    if (dp[factory_on] != INF)
        return dp[factory_on];

    for (int i = 0; i < N; i++) {
        if ( factory_on&(1 << i) ) {
            for (int j = 0; j < N; j++) {
                if ( (factory_on & (1 << j)) == 0)
                    dp[factory_on] = min(dp[factory_on], solve( factory_on|(1 << j), flag+1) + arr[i][j] );
            }
        }
    }

    return dp[factory_on];
}


int main(void) {

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    string str = "";
    int value = 0;
    int ans = 0;
    
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];
    }

    for (int j = 0; j < (1 << N); j++)
        dp[j] = INF;

    cin >> str;
    cin >> min_machine;
    
    int flag = 0;
    for (int i = 0; i < N; i++) {
        if(str[i] == 'Y') {
            value = (value | (1 << i));
            flag++;
        }
    }
    
    ans = solve(value,flag);

    if (ans >= INF) 
        cout << -1;
    else
        cout << ans;

    return 0;
}
