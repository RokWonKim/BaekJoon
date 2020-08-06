#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int w[51];

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> w[i];
        sort(w, w+n);

        int left = 2;
        int right = 100;
        int answer = 0;
        for (int i = 2; i <= 200; i++) {
            int start = 0;
            int end = n-1;
            int cnt = 0;
            while (start < end) {
                if (w[start] + w[end] == i) {
                    cnt++;
                    start++;
                    end--;
                }
                else if (w[start]+w[end] > i) {
                    end--;
                }
                else {
                    start++;
                }

            }
            answer = max(cnt,answer);
        }

        cout << answer << '\n';

    }

    return 0;
}