#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int a,b,c;
int dp[3000][3000];
string s1,s2;

int solve(int fir , int sec) {
    if (fir == s1.size() || sec == s2.size()) {
        if (fir == s1.size()) return (s2.size()-sec)*b;
        if (sec == s2.size()) return (s1.size()-fir)*b;
        return 0;
    }

    int &value = dp[fir][sec];
    if (value != -INF) return value;

    if (s1[fir] == s2[sec]) value = max(value, solve(fir+1, sec+1) + a);
    else value = max(value, solve(fir+1,sec+1)+c);
    value = max(value, solve(fir+1, sec) + b);
    value = max(value, solve(fir, sec+1) + b);

    return value;
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    fill (&dp[0][0], &dp[2999][3000], -INF);

    cin >> a >> b >>c;
    cin >> s1 >> s2;

    cout << solve(0,0) << '\n';

    return 0;
}