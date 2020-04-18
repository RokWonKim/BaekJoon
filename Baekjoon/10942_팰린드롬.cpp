#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

int N;
int arr[2001];
int dp[2001][2001];

int palin(int start, int end) {
    
    if (start >= end)
        return 1;
    
    int &value = dp[start][end];
    if (value != -1)
        return value;
    
    if (arr[start] != arr[end]) return value = 0;
    
    return value = palin(start+1,end-1);
}

int main(void) {
    
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    memset( dp, -1, sizeof(dp));
    cin >> N;
    
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    
    int q;
    cin >> q;
    
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        
        if (a > b) swap(a,b);
        cout << palin(a,b) << '\n';
    }
    return 0;
}
