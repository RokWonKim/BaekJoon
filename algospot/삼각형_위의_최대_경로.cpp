#include<iostream>

using namespace std;

int arr[105][105];

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        
        int N, ans = 0;
        cin >> N;

        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= i; j++)
                cin >> arr[i][j];

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= i; j++) {
                arr[i][j] += max(arr[i-1][j], arr[i-1][j-1]);
                ans = max(ans, arr[i][j]);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}