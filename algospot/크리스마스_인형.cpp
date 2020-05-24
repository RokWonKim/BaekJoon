#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n,k;
long long part_sum[100001];
long long mod[100001];
int check_index[100001];

int main(void) {
    ios_base:: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        memset(part_sum, 0, sizeof(part_sum));
        memset(check_index, -1, sizeof(check_index));
        memset(mod, 0 , sizeof(mod));

        long long number = 0;
        int ans = 0;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> part_sum[i];

            part_sum[i] = (part_sum[i-1] + part_sum[i]);
        }
        for (int i = 1; i <= n; i++) {
            part_sum[i] = part_sum[i] % k;
            mod[part_sum[i]]++; 
        }
        for (int i = 0; i < k; i++) {
            if (i == 0) number += mod[i];
            if (mod[i] > 1) number = (number + ((mod[i]*(mod[i]-1))/2)) % 20091101;
        }

/*
        int loc = 0;
        for (int i = 1; i <= n; i++) {
            int value = part_sum[i];

            if (check_index[value] > loc) {
                loc = i;
                ans++;
            }
            else check_index[value] = i;

        }*/

        vector<int> ret(n+1, 0);
        vector<int> prev(k,-1);
        for (int i = 0; i <= n; i++) {
            if (i > 0)ret[i] = ret[i-1];
            else ret[i] = 0;

            int loc = prev[part_sum[i]];

            if(loc!=-1) ret[i] = max(ret[i], ret[loc] +1);
            
            prev[part_sum[i]] = i;
        }

        cout << number << ' ' << ret[n] << '\n';

    }

    return 0;
}