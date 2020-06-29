#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int INF = 987654321;

int N;
int dp[500][500];
vector<pair<int,int>> arr;

int solve(int start, int end) {
    if (start == end) return 0;

    int &value = dp[start][end];
    if (value != -1) return value;
    value = INF;

    for (int i = start; i < end; i++)
        value = min(value, solve(start,i)+solve(i+1,end) + arr[start].first*arr[i].second*arr[end].second );
    return value;
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1 ,sizeof(dp));
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a,b;
        cin >> a >> b;
        arr.push_back({a,b});
    }

    cout << solve(0,N-1);

    return 0;
}