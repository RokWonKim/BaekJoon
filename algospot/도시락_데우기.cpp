#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#define f(j) for(int i = 0; i < j; i++)

using namespace std;

pair<int,int> lunch[10002];

bool compare(pair<int,int>& a, pair<int,int>& b) {
    return a.second > b.second;
}


int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        int N;
        int ans = 0;
        
        cin >> N;
        f(N) cin >> lunch[i].first;
        f(N) cin >> lunch[i].second;
        
        sort(lunch, lunch+N, compare);
        
        int part = -1;
        for (int i = 0; i < N; i++) {
            int x = lunch[i].first;
            int y = lunch[i].second;
            
            ans += x;
            part -= x;
            if (part < y) part = y;
        }
        
        if (part < 0) part = 0;
        
        cout << ans + part << '\n';

    }
    return 0;
}
