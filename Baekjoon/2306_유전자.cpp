#include <iostream>
#include <string>
#include <cstring>

using namespace std; 

const int INF = 987654321;

int dp[500][500];
string s;

int solve(int start, int end) {
    if (start >= end) return 0;

    int &value = dp[start][end];
    if (value != -1) return value;

    value = 0;

    for (int i = start; i <= end; i++) {
        if ( (s[start] == 'a' && s[i] == 't') || (s[start] == 'g' && s[i] == 'c') )
            value = max(value, solve(start+1, i-1) + 2 + solve(i+1, end) );
        
        value = max(value, solve(start, i)+ solve(i+1, end) );
    }

    return value;
}


int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    cin >> s;

    cout << solve(0,s.size()-1) << '\n';
    return 0;
}