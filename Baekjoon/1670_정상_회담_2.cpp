#include <iostream>

using namespace std;

const int MOD = 987654321;

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    long long arr[10001] = {0,};

    arr[0] = 1;
    arr[2] = 1;
    arr[4] = 2;
    for (int i = 6; i <= N; i+=2) {
        for (int j = 0; j < i; j+=2) {
            arr[i] = ( arr[i] + (arr[j] * arr[i-j-2])) % MOD;
        }
    }

    cout << arr[N] << '\n';

    return 0;
}