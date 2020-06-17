#include <string>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

const int INF = 987654321;

string s;
map<string, int> m;
int dp[20000];

int solve(int start) {
    
    if (start == s.size()) return 0;
    
    int &value = dp[start];
    if (value != -1) return value;
    
    value = INF;
    for (int i = 0; i < 5 && start+i < s.size(); i++) {
        string sub = s.substr(start, i+1);
        if (m[sub] != 0) value = min(value, solve(start+i+1)+1);
    }
    return value;
}

int solution(vector<string> strs, string t) {
    memset(dp, -1, sizeof(dp));
    s = t;
    for (int i = 0; i < strs.size(); i++) m[strs[i]] = 1;
    
    return (solve(0)==INF?-1:solve(0));
}