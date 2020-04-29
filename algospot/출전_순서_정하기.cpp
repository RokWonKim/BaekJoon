#include<iostream>
#include<algorithm>
#include<vector>
#define f(j) for(int i = 0; i < j; i++)

using namespace std;

int rusia[103];
int korea[103];

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        int N;
        int ans = 0;
        cin >> N;
        
        f(N) cin >> rusia[i];
        f(N) cin >> korea[i];
        
        sort(rusia, rusia+N);
        sort(korea, korea+N);
        
        int r_count = 0;
        int k_count = 0;
        while (k_count < N) {
            if (rusia[r_count] <= korea[k_count] ) {
                r_count++;
                ans++;
            }
            
            k_count++;
        }
        
        cout << ans << '\n';
    }
    return 0;
}
