#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int N;
int arr[16][16];
// i번 한테 있을때 누구누구에게 팔았는지 => 인원수를 저장
int dp[16][10][1 << 15];

int solve(int now, int price, int calcul) {
    
    int &value = dp[now][price][calcul];
    if (value != -1) return value;

    value = 0;
    for (int i = 0; i < N; i++) {
        if ( (calcul & (1 << i)) == 0) {
            if (arr[now][i] >= price) {
                value = max(value,solve(i, arr[now][i], calcul|(1<<i) )+1 );
            }
        }
    }

    return value;
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));

    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++)
            arr[i][j] = s[j]-'0';
    }


    cout << solve(0, 0, 1)+1 << '\n';


    return 0;
}