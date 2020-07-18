#include <iostream>
#include <cstring>

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

        for (int i= 0; i < N; i++) cin >> arr[i];
        int now = N-1;

        while(now > 0 && arr[now-1] >= arr[now]) now--;
        while(now > 0 && arr[now-1] <= arr[now]) now--;
        
        cout << now << '\n';
    }

    return 0;
}