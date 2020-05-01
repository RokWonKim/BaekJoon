#include<iostream>
#include<string.h>

using namespace std;

int arr[505];
int cache[505];

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int N, ans = 1;
        cin >> N;

        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            cache[i] = 1;
        }

        for (int i = 1; i < N; i++) {
            for(int j = 0; j < i; j++) {
                if (arr[i] > arr[j])
                    cache[i] = max(cache[i], cache[j]+1);
            }
            ans = max(ans, cache[i]);
        }

        cout << ans << '\n';
    }

    return 0;
}