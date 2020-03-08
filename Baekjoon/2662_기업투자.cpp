#include<iostream>
#include<string.h>

using namespace std;

int N, M;
int arr[301][21];
int dp[301][21];
int invest_company_money[301][21];


int solve(int remain_money, int company_num){

    if (company_num > M) 
        return 0;

    int &value = dp[remain_money][company_num];

    if (value != -1)
        return value;

    value = 0;
    for(int i = 0; i <= remain_money; i++) {
        int money = solve(remain_money-i, company_num+1)+arr[i][company_num];

        if (money > value) {
            value = money;
            invest_company_money[remain_money][company_num] = i;
        }
    }

    return value;
}

int main(void) {

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    cin >> N >> M;
    int a;

    
    for (int i = 1; i <= N; i++) {
        cin >> a;
        for (int j = 1; j <= M; j++)
            cin >> arr[a][j];
    }

    cout << solve(N,1) << '\n';

    for (int i = 1; i <= M; i++) {
        cout << invest_company_money[N][i] << ' ';
        N -= invest_company_money[N][i];
    }

    return 0;
}