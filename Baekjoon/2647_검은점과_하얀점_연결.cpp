#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 9876543;

// a~b사이를 이었을때 최소값
int N;
int arr[102];
// a~b = 가장 작은 거리
int dp[102][102];
// 거리가 가장 작을 때 높이를 저장
int height[102][102];

vector<pair<int,int>> answer_pair;

bool compare(const pair<int,int>& a, const pair<int,int>& b) {
    return a.first < b.first;
}

int solve(int left, int right) {
    if (left >= right) {
        height[left][right] = 0;
        return dp[left][right] = 0;
    }
    
    int &value = dp[left][right];
    if (value != -1) return value;

    value = INF;
    for (int i = left; i <= right ; i++) {
        if (arr[left] != arr[i] && (i-left)%2 == 1) {
            int l = solve(left+1, i-1);
            int r = solve(i+1, right);
            int h1 = (i-left) + 2*(height[left+1][i-1]+1);
            if (value > l+r+h1) {
                value = l+r+h1;
                height[left][right] = max(height[left+1][i-1]+1, height[i+1][right]) ;
            }
        }

        if (arr[right] != arr[i] && (right-i)%2 == 1) {
            int l = solve(i+1, right-1);
            int r = solve(left, i-1);
            int h2 = (right-i) + 2*(height[i+1][right-1]+1);
            if (value > l+r+h2) {
                value = l+r+h2;
                height[left][right] = max(height[left][i-1], height[i+1][right-1]+1);
            }
        }
    }

    return value;
}

void trace(int left, int right, int value) {
    if (left >= right) return;

    for (int i = left; i <= right; i++) {
        if (arr[left] != arr[i] && (i-left)%2 == 1) {
            int l = solve(left+1, i-1);
            int r = solve(i+1,right);
            int h = 2*height[left][right] + (i-left);
            if (value == l+r+h) {
                trace(left+1, i-1, l);
                trace(i+1, right, r);
                answer_pair.push_back({left , i});
                return;
            }
        }
        if (arr[right] != arr[i] && (right-i)%2 == 1) {
            int l = solve(i+1, right-1);
            int r = solve(left, i-1);
            int h2 = (right-i) + 2*(height[i+1][right-1]+1);
            if (value == l+r+h2) {
                trace(i+1, right-1, l);
                trace(left, i-1, r);
                answer_pair.push_back({i, right});
                return;
            }
        }
    }    

}

int main(void) {

    memset(dp, -1, sizeof(dp));
    fill(&height[0][0], &height[101][102], INF);

    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%1d", &arr[i]);

    int answer = solve(0,N-1);
    trace(0,N-1, answer);
    sort(answer_pair.begin(), answer_pair.end(), compare);

    printf("%d\n", answer);
    for (pair<int,int>& v : answer_pair)
        printf("%d %d\n", v.first+1,v.second+1);

    return 0;
}