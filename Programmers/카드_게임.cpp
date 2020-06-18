#include <string>
#include <vector>
#include <cstring>

using namespace std;

int dp[2000][2000];
vector<int> left,right;
int size;

int solve(int l, int r) {
    
    if (l == size || r == size) return 0;
    
    int &value = dp[l][r];
    if (value != -1) return value;
    
    if (left[l] > right[r]) value = max(value, solve(l,r+1)+right[r]);
    value = max(value, solve(l+1, r));
    value = max(value, solve(l+1, r+1));
    
    return value;
}

int solution(vector<int> le, vector<int> ri) {
    memset(dp, -1, sizeof(dp));
    left = le;
    right = ri;
    size = le.size();
    
    return solve(0,0);
}