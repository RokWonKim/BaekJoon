#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int INF = 987654321;

vector<vector<int>> arr;
int dp[201][201];

int solve(int start, int end) {
    if (start == end) return 0;
    
    int &value = dp[start][end];
    if(value != -1) return value;
    
    value = INF;
    for (int i = start; i < end; i++)
        value = min(value ,(solve(start,i)+solve(i+1, end)) + arr[start][0]*arr[i][1]*arr[end][1]);
    
    return value;
}

int solution(vector<vector<int>> matrix_sizes) {
    memset(dp,-1,sizeof(dp));
    arr = matrix_sizes;
    
    return solve(0, matrix_sizes.size()-1);
}