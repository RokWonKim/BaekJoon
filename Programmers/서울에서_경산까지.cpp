#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int INF = 987654321;

vector<vector<int> > travel;
int max_time;
int s;
int dp[100][100001][2];

//way가 0이면 도보 1이면 자전거
int solve(int now, int part_time, int way) {
    
    if (part_time > max_time) return -INF;
    if (now == s) return 0;
    
    int &value = dp[now][part_time][way];
    if (value != -1) return value;
    
    value = max(value, solve(now+1, part_time+travel[now][0], 0) + travel[now][1]);
    value = max(value, solve(now+1, part_time+travel[now][2], 1) + travel[now][3]);
    
    return value;
}


int solution(int K, vector<vector<int>> t) {
    memset(dp, -1, sizeof(dp));
    s = t.size();
    max_time = K;
    travel = t;
    
    return solve(0,0,0);
}