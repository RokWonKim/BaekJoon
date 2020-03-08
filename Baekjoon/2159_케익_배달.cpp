#include<iostream>
#include<string.h>
#include<cmath>

using namespace std;

int N;

pair<int, int> arr[100002];
long long dp[100002][5];
int m[5][2] = { {-1,0}, {1,0}, {0,-1}, {0,1}, {0,0} };


long long diff_distance(pair<int,int>& i, pair<int,int>& j) {
    return (abs(i.first - j.first) + abs(i.second - j.second))*1LL;
}

long long solve(int index, int direction) {

    if (index == N)
        return 0;
    
    long long &value = dp[index][direction];
    if (value != -1)
        return value;

    value = 1e15;
    pair<int,int> now = {arr[index].first+m[direction][0], arr[index].second+m[direction][1]};
    for (int i = 0; i < 4; i++) {
        pair<int,int> next = {arr[index+1].first+m[i][0], arr[index+1].second+m[i][1]};
        value = min(value, solve(index+1,i) + diff_distance(now,next) );
    }

    return value;
}

int main(void) {

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    memset( dp, -1, sizeof(dp) );

    cin >> N;

    for (int i = 0; i <= N; i++)
        cin >> arr[i].first >> arr[i].second;

    cout << solve(0, 4);

    return 0;
}