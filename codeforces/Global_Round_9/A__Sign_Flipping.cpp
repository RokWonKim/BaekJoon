#include <iostream>
#include <cmath>

using namespace std;

int arr[100];

int main(void) {
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        for(int i = 0; i < N; i++) {
            cin >> arr[i];
            arr[i] = abs(arr[i]);
        }

        for (int i = 0; i < N; i++) {
            if (i % 2 == 0) cout << -arr[i] << ' ';
            else cout << arr[i] << ' ';

        }
        cout << '\n';
    }
    
    
    return 0;
}