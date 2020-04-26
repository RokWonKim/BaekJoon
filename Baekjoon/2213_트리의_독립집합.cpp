#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>

using namespace std;

int N;
int weight[10001];
vector<int> graph[10001];
vector<int> ans;

//index, 나 선택x, o
int dp[10001][2];


int solve(int x, int me, int parent) {
    
    if ( graph[x].size() == 1 && graph[x][0] == parent)
        return me==1?(dp[x][me]=weight[x]):(dp[x][me]=0);
    
    int &value = dp[x][me];
    if (value != -1)
        return value;
    
    value = me==1?weight[x]:0;
    for (int a : graph[x]) {
        if (a == parent) continue;
        
        if (me == 0)
            value += max(solve(a, 0, x), solve(a, 1, x));
        else
            value += solve(a,0,x);
    }
    
    return value;
}

void trace(int x, int me, int parent) {
    
    if (me == 1) ans.push_back(x);
    for (int a : graph[x] ) {
        if (a == parent) continue;
        
        if (me == 1) {
            trace(a, 0, x);
        }
        else {
            if (dp[a][1] > dp[a][0])
                trace(a,1,x);
            else
                trace(a,0,x);
        }
    }
    
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    memset(dp, -1, sizeof(dp));
    
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> weight[i];
    
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    
    int left = solve(1,0,-1);
    int right = solve(1,1,-1);
    
    if (left > right) trace(1,0,-1);
    else trace(1,1,-1);
    
    sort(ans.begin(), ans.end());
    
    cout << max(left,right) << '\n';
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    
    return 0;
}
