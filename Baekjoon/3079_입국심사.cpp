#include<iostream>

using namespace std;

long long arr[100001];

int main(void) {

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    long long N, M;
    long long max_value = 0;
    long long left = 1;
    long long right = 0;
    long long ans;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        max_value = max(max_value, arr[i]);
    }

    right = M * max_value;    
    ans = right;

    while (left <= right) {
        long long mid = (left + right) / 2;
        long long sum = 0;

        for (int i = 0; i < N; i++)
            sum += mid / arr[i];

        if ( sum >=  M ) {
            ans = min(ans, mid);
            right = mid - 1;
        }
        else
            left = mid + 1;
    }

    cout << ans;

    return 0;
}