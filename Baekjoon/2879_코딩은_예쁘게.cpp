#include <iostream>
#include <cmath>

using namespace std;

int N;
int arr[1001];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        arr[i] -= a;
    }

    int ans = 0;
    int pre = arr[0];
    
    for (int i = 1; i < N; i++) {
        
        if (arr[i] >= 0) {
            if (pre < 0)
                ans += abs(pre);
            else if (pre > arr[i])
                ans += abs(pre) - abs(arr[i]);
        }
        else {
            if (pre > 0)
                ans += pre;
            else if ( pre <= arr[i] )
                ans += abs(pre) - abs(arr[i]);
        }
        
        pre = arr[i];
    }

    ans += abs(pre);
    cout << ans;

    return 0;

}
