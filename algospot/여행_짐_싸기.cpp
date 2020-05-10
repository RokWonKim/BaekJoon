#include<iostream>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

struct info {
    string name;
    int w;
    int please;
};

int N,W;
vector<info> arr;
vector<string> ans_name;
int dp[101][1001];

int solve(int now_index, int weight) {

    if (now_index == N) return 0;

    int &value = dp[now_index][weight];
    if (value != -1) return value;

    value = 0;
    int ans_1 = solve(now_index+1, weight);
    int ans_2 = 0;

    if (weight + arr[now_index].w <= W)
        ans_2 = solve(now_index+1, weight + arr[now_index].w) + arr[now_index].please;
    
    value = max(ans_1, ans_2);

    return value;
}

void trace(int index, int weight) {
    if ( index == N-1 ) {
        if (dp[index][weight] != 0)
            ans_name.push_back(arr[index].name);
        return;
    }
    if ( dp[index][weight] == dp[index+1][weight] )
        trace(index+1, weight);
    else {
        ans_name.push_back(arr[index].name);
        trace(index+1,weight+arr[index].w);
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--) {
        memset(dp, -1, sizeof(dp));
        ans_name.clear();
        arr.clear();
        
        cin >> N >> W;
        
        string s;
        int part_w, part_please;
        for(int i = 0; i < N; i++) {
            cin >> s >> part_w >> part_please;
            arr.push_back({s,part_w,part_please});
        }

        int ans = solve(0,0);

        trace(0, 0);
        cout << ans << ' ' << ans_name.size() << '\n';
        for (int i = 0; i < ans_name.size(); i++)
            cout << ans_name[i] << '\n';
    }

    return 0;
}