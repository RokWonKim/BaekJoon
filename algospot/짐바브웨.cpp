#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

const int MOD = 1000*1000*1000+7;
long long e;
string str_e, sort_e;
int m, n;

int dp[1 << 15][20][2];

// less가 0이면 아직 기존 e보다 큰지 작은지 모른다는 거
int solve(int index, int taken, int mod, int less) {

    if (index == n)
        return (less && mod == 0) ? 1 : 0;

    //각 자리수를 사용했는지, 나머지가 몇인지, 본래 값보다 큰지작은지,
    int &value = dp[taken][mod][less];
    if (value != -1) return value;

    value = 0;
    for (int i = 0; i < n; i++) {
        // 아직 사용하지 않은 것만
        if ( (taken & (1 << i)) == 0) {
            // 본래 값보다 작다고 판명나지 않은 곳에서 현 값이 더 크다면
            if (less == 0 && str_e[index] < sort_e[i]) continue;
            // 같은 수가 있다면 전에꺼부터 사용하게 하기 위한 것(그래야 같은수가 석이는 것을 방지함)
            if (i > 0 && sort_e[i-1] == sort_e[i] && (taken & (1 << (i-1)))==0 ) continue;

            // 이번 값을 사용할 것이니 사용했다고 표기
            int nexttaken = taken | (1 << i);
            // 나머지 값을 최신화
            int nextmod = (mod*10 + (sort_e[i]-'0')) % m;
            // 이제 다시 본래값보다 큰지 안큰지 확인
            int nextless = less || str_e[index] > sort_e[i];
            
            value = ( value + solve(index+1, nexttaken, nextmod, nextless) ) % MOD;
        }

    }
    return value;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        memset(dp,-1,sizeof(dp));
        cin >> e >> m;
        
        str_e = to_string(e);
        sort_e = to_string(e);
        n = str_e.size();
        sort(sort_e.begin(), sort_e.end());

        cout << solve(0, 0, 0, 0) <<'\n';
    }

    return 0;
}