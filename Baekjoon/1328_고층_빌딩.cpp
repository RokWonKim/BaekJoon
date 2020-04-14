#include<iostream>
#include<string.h>

using namespace std;

const long long mod = 1000000007;
int N,L,R;

// 빌딩 수, 왼쪽에서 보이는 거, 우측에서 보이는거,
long long dp[101][101][101];

long long solve(int number, int left, int right) {
    
    
    if (right == 1 && left == number)
        return 1;
    if (left == 1 && right == number)
        return 1;
    
    if (left == 0 || right == 0 || number == 0)
        return 0;
    
    long long &value = dp[number][left][right];
    if (value != -1)
        return value;
    
    value = 0;
    value += (solve(number-1, left-1, right) + solve(number-1, left, right-1) + solve(number-1,left,right)*(number-2))%mod;
    
    return value;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    memset(dp, -1, sizeof(dp));
    cin >> N >> L >> R;
    
    cout << solve(N,L,R)% mod;
    
    return 0;
}
