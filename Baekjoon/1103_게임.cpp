#include<iostream>
#include<string>
#include<set>
#include<string.h>

using namespace std;

int N,M;

int arr[51][51];
int m[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

//x,y,4방향중 어디에서 왔는지
int dp[51][51];
set<pair<int,int> > s;

int solve(int x, int y) {
    
    if (x < 0 || x >= N || y < 0 || y >= M )
        return 0;
    if (arr[x][y] == 'H')
        return 0;
    if (s.find({x,y}) != s.end()) {
        cout << -1;
        exit(0);
    }
    
    int &value = dp[x][y];
    if (value != -1)
        return value;
    
    value = 0;
    s.insert({x,y});
    for (int i = 0; i < 4; i++) {
        int new_x = x + m[i][0]*arr[x][y];
        int new_y = y + m[i][1]*arr[x][y];
        
        value = max(value, solve(new_x,new_y)+1);
    }
    s.erase({x,y});
    
    return value;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    memset(dp, -1, sizeof(dp));
    
    cin >> N >> M;
    string str;
    
    for (int i = 0; i < N; i++) {
        cin >> str;
        for (int j = 0; j < M; j++)
            if(str[j] != 'H')
                arr[i][j] = str[j] - '0';
            else
                arr[i][j] = str[j];
    }
    
    cout << solve(0,0) <<'\n';
    
    return 0;
}
