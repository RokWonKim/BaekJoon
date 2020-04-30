#include<iostream>
#include<queue>

using namespace std;

int main(void) {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    while(T--) {
        int N;
        int ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        cin >> N;
        
        for (int i = 0; i < N; i++) {
            int value;
            cin >> value;
            pq.push(value);
        }
        
        while(pq.size() != 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            
            pq.push(x+y);
            ans += x+y;
        }
        
        cout << ans <<'\n';
    }
    
    return 0;
}
