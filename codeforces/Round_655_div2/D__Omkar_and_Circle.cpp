#include <iostream>

using namespace std;

int arr[200001];

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int N;
    long long ms = 0;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    for (int i = 0; i < N; i+=2) ms += arr[i];

    long long answer = ms;
    for (int i = 0; i < N; i+=2) {
        ms -= arr[i];
        ms += arr[ (i+1) % N];
        answer = max(answer, ms);
    }
    for (int i = 1; i < N; i+=2) {
        ms -= arr[i];
        ms += arr[(i+1) % N];
        answer = max(answer,ms);
    }

    cout << answer << '\n';

    return 0;
}