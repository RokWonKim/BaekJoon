#include<iostream>
#include<vector>
#include<string.h>

const int INF = 100000000;
using namespace std;

int N;
vector<int> arr[1000001];

//정점 자신이 얼리 어답터 거나 아니거나
int dp[1000001][2];

//현재 정점, 전 정점, 전이 얼리 어답터 였다
int solve(int pre_v, int v, int early) {
    
    if( arr[v].size() == 1 && pre_v != -1) {
        if (early == 0)
            return 0;
        else
            return 1;
    }
    
    int &value = dp[v][early];
    if (value != -1)
        return value;
    
    value = INF;
    int part_value = 0;
    if (early == 1)
        part_value++;
    for (auto a : arr[v]) {
        if (pre_v == a) continue;
        
        if (early == 0)
            part_value += solve(v,a,1);
        else if(early == 1)
            part_value += min(solve(v,a,1), solve(v,a,0));
    }
    value = min(value, part_value);
    
    return value;
}

int main(void) {
    
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    memset(dp, -1, sizeof(dp));
    
    cin >> N;
    
    for (int i = 0; i < N-1; i++) {
        int a,b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    
    cout << min(solve(-1,1,0), solve(-1,1,1) );
    
    return 0;
}
