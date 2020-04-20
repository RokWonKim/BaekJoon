#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int A[4002];
int B[4002];
int C[4002];
int D[4002];
vector<int> sumAB;
vector<int> sumCD;

int main(void) {

    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    long long ans = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    
    for (int i = 0 ; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sumAB.push_back(A[i] + B[j]);
            sumCD.push_back(C[i] + D[j]);
        }
    }
    
    sort(sumAB.begin(), sumAB.end());
    sort(sumCD.begin(), sumCD.end());
    
    int ab_loc = 0;
    int cd_loc = sumCD.size()-1;
    
    while(ab_loc < sumAB.size() && cd_loc >= 0 ) {
        
        if ( sumAB[ab_loc] + sumCD[cd_loc] > 0)
            cd_loc--;
        else if ( sumAB[ab_loc] + sumCD[cd_loc] < 0)
            ab_loc++;
        else {
            long long  ab_count = 0;
            long long cd_count = 0;
            int i;
            int j;
            
            for (i = ab_loc; i < sumAB.size() && sumAB[ab_loc] == sumAB[i]; i++)
                ab_count++;
            for (j = cd_loc; j >= 0 && sumCD[cd_loc] == sumCD[j]; j--)
                cd_count++;
            ans += (ab_count*cd_count);
            ab_loc = i;
            cd_loc = j;
        }
        
    }
    
    
    cout << ans;
    
    return 0;
}
