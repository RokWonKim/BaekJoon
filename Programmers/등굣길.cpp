#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int mod = 1000000007;

int d[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
int arr[101][101];
int dp[101][101];
int n;
int m;

int solve(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return 0;
    if (arr[x][y] == -1) return 0;
    if (x == n-1 && y == m-1) return 1;
    
    int &value = dp[x][y];
    if (value != -1) return value;
    
    value = solve(x+1,y);
    value = (value + solve(x, y+1)) % mod;
    
    return value;
}

int solution(int b, int a, vector<vector<int>> puddles) {
    memset(dp, -1, sizeof(dp));
    n = a;
    m = b;
    
    for (int i = 0; i < puddles.size(); i++)
        arr[puddles[i][1]-1][puddles[i][0]-1] = -1;
    
    return solve(0, 0);
}