#include<iostream>
#include<cmath>
#include<string.h>

using namespace std;

int N, W;

int dp[1001][1001];
int next_move_pol[1001][1001];

pair<int, int> location[1001];

int calcul_dis(pair<int, int>& i, pair<int, int>& j) {
    return abs(i.first-j.first) + abs(i.second-j.second);
}

int move(int pol_1, int pol_2) {
    
    if (dp[pol_1][pol_2] != -1)
        return dp[pol_1][pol_2];


    int incident = max(pol_1, pol_2)+1;

    if (incident == W+2)
        return 0;

    int pol_1_move = move(incident, pol_2) + calcul_dis(location[pol_1],location[incident]); 
    int pol_2_move = move(pol_1, incident) + calcul_dis(location[pol_2], location[incident]);


    if (pol_1_move < pol_2_move)
        dp[pol_1][pol_2] = pol_1_move;
    else {
        dp[pol_1][pol_2] = pol_2_move;
        next_move_pol[pol_1][pol_2] = 1;
    }


    return dp[pol_1][pol_2];
}


int main(void) {

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    cin >> N >> W;

    location[0] = {1,1};
    location[1] = {N, N};

    for (int i = 2; i < W+2; i++)
        cin >> location[i].first >> location[i].second;
    
    int distance = move(0,1);

    cout << distance << '\n';

    int pol_1 = 0;
    int pol_2 = 1;

    while( max(pol_1, pol_2) < W+1 ) {
        int next = next_move_pol[pol_1][pol_2] +1;

        cout << next << '\n';

        if (next == 2)
            pol_2 = max(pol_1, pol_2)+1;
        else
            pol_1 = max(pol_1, pol_2)+1;
    }


    return 0;
}