#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

int N;
int person[10001];
vector<int> con[10001];

//지금 나를 기준, 내가 우수마을인가 아닌가
int dp[10001][2];

int solve(int index, int me, int parent) {
    
    if (con[index].size() == 1 && con[index][0] == parent) {
        if (me == 0)
            return 0;
        else
            return person[index];
    }
    
    int &value = dp[index][me];
    if (value != -1)
        return value;
    
    if ( me == 1) value = person[index];
    else value = 0;
    
    for (int next : con[index]) {
        if (next == parent) continue;
        
        if (me == 0)
            value += max( solve(next,1,index) , solve(next,0,index) );
        else
            value += solve(next,0,index);
    }
    
    return value;
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    memset(dp, -1, sizeof(dp));
    
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> person[i+1];
    
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        con[a].push_back(b);
        con[b].push_back(a);
    }
    
    cout << max(solve(1,0,-1), solve(1,1,-1)) << '\n';
    return 0;
}
