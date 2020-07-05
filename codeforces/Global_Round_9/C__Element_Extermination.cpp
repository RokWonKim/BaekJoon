#include <iostream>

using namespace std;

int arr[300001];

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        if (arr[0] < arr[N-1]) cout << "YES\n";
        else cout << "NO\n";

    }

    return 0;
}