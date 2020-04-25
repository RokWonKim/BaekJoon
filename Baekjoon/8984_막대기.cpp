#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

long long top_dp[100001];
long long down_dp[100001];
vector< pair<int,int> > arr;
vector<int> top;
vector<int> down;

bool compare(pair<int,int>& a , pair<int,int>& b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    int N,L;
    long long ans = 0;
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        int a,b;
        cin >> a >> b;
        arr.push_back({a,b});
        top.push_back(a);
        down.push_back(b);
    }
    
    sort(arr.begin(),arr.end(), compare);
    sort(top.begin(), top.end());
    sort(down.begin(), down.end());
    
    top.erase(unique(top.begin(),top.end()), top.end());
    down.erase(unique(down.begin(), down.end()), down.end());
    
    
    for (int i = 0; i < N; i++) {
        int t = arr[i].first;
        int d = arr[i].second;
        
        int plus = L+abs(t-d);
        
        int t_index = lower_bound( top.begin(), top.end(), t)-top.begin();
        int d_index = lower_bound( down.begin(), down.end(), d)-down.begin();
        long long copy_t = top_dp[t_index];
        long long copy_d = down_dp[d_index];
        
        top_dp[t_index] = max(copy_t, copy_d+plus);
        down_dp[d_index] = max(copy_d, copy_t+plus);
        ans = max(ans, max(top_dp[t_index], down_dp[d_index]));
    }
    
    cout << ans;
    
    return 0;
}
