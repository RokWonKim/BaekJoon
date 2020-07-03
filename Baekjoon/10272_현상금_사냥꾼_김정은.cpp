#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

const double INF = 987654321;

int N;
//start에서 시작해서 end로 끝나는 바이토닉 투어
double dp[515][515];
vector<pair<int,int>> arr;

double dist(const pair<int,int>& a, const pair<int,int>& b) {
    return sqrt( pow(a.first-b.first,2) + pow(a.second-b.second,2) );
}

double solve(int start, int end) {
    if (start == N-1) return dist(arr[end], arr[N-1]);
    if (end == N-1) return dist(arr[start], arr[N-1]);

    double &value = dp[start][end];
    if (value != 0) return value;

    int next = max(start, end) + 1;

    value = min(solve(start, next) + dist(arr[next],arr[end]), solve(next, end) + dist(arr[next],arr[start]));

    return value;
}

int main(void) {
    int T;
    scanf("%d", &T);

    while(T--) {
        scanf("%d", &N);
        memset(dp, 0, sizeof(dp));
        arr.clear();

        for(int i = 0; i < N; i++) {
            int a,b;
            scanf("%d %d", &a, &b);
            arr.push_back({a,b});
        }

        printf("%.3lf\n", solve(0,0));
    }

    return 0;
}