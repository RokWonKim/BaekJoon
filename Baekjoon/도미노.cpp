#include <iostream>

using namespace std;

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    //차수에 따라 나올 수 있는 경우의 수
    int dp[10] = {0,};
    int number[10] = {0,};
    long long answer = 1;

    dp[0] = 1;

    for (int i = 2; i < 10; i++) dp[i] = (i-1) * dp[i-2];

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;

        number[a/10]++;
        number[a%10]++;
    }

    for (int i = 0; i < 10; i++) answer *= dp[number[i]];

    cout << answer << '\n';

    return 0;
}