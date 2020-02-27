#include<iostream>
#include<algorithm>

using namespace std;

int N, T;
int arr[100001];
int change[100001];

bool confirm( int diff_p_to_p ) {
    int sum_diff = 0;

    for (int i =0; i < N; i++)
        change[i] = arr[i];
    

    for (int n = 0;n < N - 1;n++) {
        if (change[n] + diff_p_to_p < change[n + 1]) {
            sum_diff += change[n + 1] - (change[n] + diff_p_to_p);
            change[n + 1] = change[n] + diff_p_to_p;
        }
    }

    for (int n = N - 1;n > 0;n--) {
        if (change[n] + diff_p_to_p < change[n - 1]) {
            sum_diff += change[n - 1] - (change[n] + diff_p_to_p);
            change[n - 1] = change[n] + diff_p_to_p;
        }
    }

    return sum_diff <= T;
}


int main(void) {
    
    int left = 0;
    int right = 0;
    int ans = 2100000000;

    int value;

    cin >> N >> T;
    
    cin >> arr[0];
    for (int i = 1; i < N; i++) {
        cin >> arr[i];
        value = abs(arr[i] - arr[i-1]);
        right = max(right, value);
    }

    while (left <= right) {
        int mid = (left + right) / 2;

        bool t_f = confirm(mid);

        if(t_f == true) {
            right = mid-1;
            ans = min(ans, mid);
        }
        else
            left = mid+1;
    }

    confirm(ans);

    for (int i =0; i < N; i++)
        cout << change[i] << ' ';

    return 0;
}