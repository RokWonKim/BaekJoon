#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--) {
        int arr[3];
        cin >> arr[0] >> arr[1] >> arr[2];
        sort(arr, arr+3);

        if ( arr[1] != arr[2]) cout << "NO\n";
        else {
            cout << "YES\n";
            cout << arr[0] << ' ' << arr[0] << ' ' << arr[2] << '\n';
        }

    }

    return 0;
}