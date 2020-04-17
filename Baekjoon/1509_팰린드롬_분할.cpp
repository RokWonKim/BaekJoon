#include<iostream>
#include<string>
#include<string.h>

using namespace std;


char str[2500];
int dp[2500][2500];
int ans[2500];

int confirm(int start, int end) {
    
    if (start >= end)
        return 1;
    
    int &value = dp[start][end];
    if (value != -1)
        return value;
    
    if (str[start] != str[end] )
        return value = 0;
    return value = confirm(start+1, end-1);
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    memset(dp,-1, sizeof(dp));
    cin >> str;
    int num = 0;
    while(str[num++]);
    int size = num-1;
    
    for(int i = 0; i < size; i++) {
        ans[i] = (i==0? 0 :ans[i-1] )+1;
        for (int j = 0; j < i; j++) {
            if (confirm(j ,i) == 0)continue;
            ans[i] = min(ans[i],( j==0 ? 0 : ans[j-1])+ 1 );
        }
    }
    cout << ans[size-1] << '\n';
    
    return 0;
}
