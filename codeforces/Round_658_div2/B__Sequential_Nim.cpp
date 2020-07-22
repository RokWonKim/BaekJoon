
#include <iostream>
#include <cstring>

using namespace std;

int arr[100001];

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int N;
        int cnt = 0;
        bool check = false;
        int index = 0;
        cin >> N;

        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
            if (arr[i] == 1) cnt++;
            if (!check && arr[i] != 1) {
                check = true;
                index = i;
            }
        }

        if (cnt == N) {
            if (cnt % 2 == 0) cout << "Second\n";
            else cout << "First\n";
        }
        else {
            if (index % 2 == 1) cout << "First\n";
            else cout << "Second\n";
        }



    }


    return 0;
}
