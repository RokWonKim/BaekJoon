#include<iostream>
#include<vector>

using namespace std;

struct info{
    int l;
    int m;
    int g;
};

vector<info> arr;

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int N, K;
        cin >> N >> K;
        arr.clear();
        for (int i = 0; i < N; i++) {
            int a,b,c;
            cin >> a >> b >> c;
            arr.push_back({a,b,c});
        }

        int left = 1;
        int right = 8030000;
        int mid = 0;
        int ans = 0;
        while(left <= right) {
            mid = (left + right) /2;
            int value = 0;

            for (int i = 0; i < N; i++) {
                if (mid >= arr[i].l-arr[i].m) {
                    value += (min(mid, arr[i].l) - (arr[i].l - arr[i].m)) / arr[i].g+1 ;
                }
            }

            if (value >= K) {
                right = mid-1;
                ans = mid;
            }
            else left = mid+1;
        }

        cout << ans << '\n';

    }

    return 0;
}