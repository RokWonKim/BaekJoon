#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int arr[200001];

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        for (int i = 1; i <= N; i++) cin >> arr[i];

        int answer = 0;
        int flag = false;
        for (int i = 1; i <= N; i++) {
            if (arr[i] == i) {
                if (answer == 0) continue;
                else if (answer == 1) flag = true;
            }
            else {
                if (answer == 0)
                    answer = 1;
                else if (flag)
                    answer = 2;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}