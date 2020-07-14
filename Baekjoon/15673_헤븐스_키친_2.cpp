#include <iostream>
#include <cstring>

using namespace std;

const long long INF = 1e16;

int N;
long long arr[100001];

long long now_min[100001];
long long now_max[100001];

long long left_min[100001];
long long left_max[100001];

long long right_min[100001];
long long right_max[100001];

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    left_min[1] = left_max[1] = arr[1];
    now_min[1] = now_max[1] = arr[1];
    for (int i = 2; i <= N; i++) {
        if (now_min[i-1] > 0) now_min[i] = arr[i];
        else now_min[i] = now_min[i-1] + arr[i];

        if (now_max[i-1] < 0) now_max[i] = arr[i];
        else now_max[i] = now_max[i-1] + arr[i];

        left_min[i] = min(left_min[i-1],now_min[i]);
        left_max[i] = max(left_max[i-1],now_max[i]);
    }

    right_min[N] = right_max[N] = arr[N];
    now_min[N] = now_max[N] = arr[N];
    for (int i = N-1; i >= 1; i--) {
        if (now_min[i+1] > 0) now_min[i] = arr[i];
        else now_min[i] = now_min[i+1]+arr[i];

        if (now_max[i+1] < 0) now_max[i] = arr[i];
        else now_max[i] = now_max[i+1] + arr[i];

        right_min[i] = min(right_min[i+1], now_min[i] );
        right_max[i] = max(right_max[i+1], now_max[i] );
    }

    long long answer = -INF;
    for (int i = 1; i < N; i++) {
        answer = max(answer, left_min[i]*right_min[i+1] );
        answer = max(answer, left_max[i]*right_max[i+1] );
    }

    cout << answer << '\n';
    

    return 0;
}