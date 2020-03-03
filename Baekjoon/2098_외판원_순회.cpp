#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

const int INF = 2000000000;

int N, all_visit;
int arr[16][16];

int dp[16][1 << 16];


int tsp(int v, int visit_vs) {

    if (visit_vs == all_visit) {
        if (arr[v][0] == 0)
            return INF;
        else
            return arr[v][0];
    }

    if (dp[v][visit_vs] != INF)
        return dp[v][visit_vs];


    for (int i = 0; i < N; i++) {
        if( ( visit_vs&(1 << i) ) == 0 && arr[v][i] != 0 )
            dp[v][visit_vs] = min(dp[v][visit_vs], tsp(i, (visit_vs|(1 << i)) ) + arr[v][i] );
    }

    return dp[v][visit_vs];    
}


int main(void) {

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    

    cin >> N;
    all_visit = (1 << N)-1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];

        for(int j = 0; j < (1 << N); j++)
            dp[i][j] = INF;

    }

    cout << tsp(0, 1);

    return 0;
}