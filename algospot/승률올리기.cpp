#include<iostream>
#include<vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        long long N, M;
        cin >> N >> M;
        long long now = (double)M*100/N;
        
        long long left = 1;
        long long right = 2*1000*1000*1000 + 1;
        for(int i = 0;i < 100; i++) {
            long long mid = (left+right)/2;
            long long value = (double)(M+mid)*100/(N+mid);
            if (value > now) right = mid;
            else left = mid;
        }

        if (right == 2*1000*1000*1000 + 1) cout << -1 <<'\n';
        else cout << right << '\n';

    }

    return 0;
}