#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int N;
int max_diff = 0;
int arr[100001];

long long move_sum( int move ) {
    long long sum_diff = 0;

    for (long long i = 1; i < N; i++)
        sum_diff += abs(arr[i] - 1LL*move*i );

    return sum_diff;
}


int main(void) {

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    long long ans = 1e18;

    cin >> N;
    cin >> arr[0];

    for (int i = 1; i < N; i++) {
        cin >> arr[i];
        max_diff = max( max_diff, arr[i] - arr[i-1] );
    }

    int left = 0;
    int right = max_diff;

    while (right - left >= 3) {
        int p = (left*2 + right)/3;
        int q = (left + right*2)/3;

        if ( move_sum(p) > move_sum(q) )    left = p;
        else    right = q;
    }

    for (int i = left; i <= right; i++) {
        ans = min(ans,move_sum(i));
    }

    cout << ans;

    return 0;
}