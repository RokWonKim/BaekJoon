#include <iostream>
#include <cstring>

using namespace std;

const int INF = 987654321;

int N,M;
bool dotc[10001];
//지금 인덱스
int dp[10001][500];

int solve(int index, int x) {
    if (dotc[index] || N <= index) return INF;
    if (N-1 == index) return 0;

    int &value = dp[index][x];
    if (value != -1) return value;

    value = INF;
    if (index == 0)
        value = solve(index+1, 1)+1;
    else {
        value = min(value, solve(index+x, x) + 1 );
        value = min(value, solve(index+x+1, x+1) + 1);
        
        if (x != 1)
            value = min(value , solve(index+(x-1), x-1) +1);
    }

    return value;
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        dotc[a-1] = true;
    }

    int answer = solve(0,0);
    if (answer >= INF) cout << -1 << '\n';
    else cout << answer << '\n';

    return 0;
}