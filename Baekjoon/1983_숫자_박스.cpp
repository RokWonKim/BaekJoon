#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;

// 현재 index에서 top과 bottom이 어디까지 왔나
int dp[401][401][401];
vector<int> top;
vector<int> bottom;
int a,b;
int N;

int solve(int index, int t_s, int b_s) {
    if (t_s == a && b_s ==b) return 0;
    if (index == N) return -INF;

    int &value = dp[index][t_s][b_s];
    if (value != -INF) return value;

    if (t_s != a)
        value = max(value, solve(index+1, t_s+1, b_s) );
    if (b_s != b)
        value = max(value, solve(index+1, t_s, b_s+1) );
    if (t_s != a && b_s != b)
        value = max(value , solve(index+1, t_s+1, b_s+1) + top[t_s]*bottom[b_s] );
    
    
    return value;
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    fill(&dp[0][0][0], &dp[400][400][401], -INF);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int v;
        cin >> v;
        if (v != 0) top.push_back(v);
    } 

    for (int i = 0; i < N; i++) {
        int v;
        cin >> v;
        if (v != 0) bottom.push_back(v);
    }

    a = top.size();
    b = bottom.size();

    cout << solve(0,0,0) <<'\n';
    return 0;
}