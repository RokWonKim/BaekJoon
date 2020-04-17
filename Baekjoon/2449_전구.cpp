#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

int N,K;
int num;
int arr[201];

//index start ~ end
int dp[201][201];

int solve(int start, int end) {
    
    if (start == end)
        return 0;
    
    int &value = dp[start][end];
    if (value != 168430090)
        return value;
    
    for(int i = start; i < end; i++)
        value = min(value, solve(start,i)+solve(i+1,end) + (arr[i]==arr[end]?0:1) );
    
    return value;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    memset(dp,10, sizeof(dp));
    cin >> N >> K;
    
    cin >> arr[0];
    for (int i = 1; i < N; i++) {
        int value;
        cin >> value;
        if (value != arr[num])
            arr[++num] = value;
    }
    
    cout << solve(0,num);
    
    return 0;
}
