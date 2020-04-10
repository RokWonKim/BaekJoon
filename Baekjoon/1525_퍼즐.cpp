#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<string>

using namespace std;

int m[4] = { 1,-1,3,-3 };

bool BFS(int now) {
    
    queue<pair<int,int>> q;
    set<int> s;
    q.push({now, 0});
    
    while(!q.empty()) {
        int x = q.front().first;
        int value = q.front().second;
        q.pop();
        
        if (x == 123456780) {
            cout << value;
            return false;
        }
        
        if (s.find(x) != s.end()) continue;
        s.insert(x);
        
        int zero_locate = 0;
        string str = to_string(x);
        
        if (x < 100000000)
            str = '0'+ str;
        
        for (int i = 0; i < 9; i++) {
            if ( str[i] == '0') {
                zero_locate = i;
                break;
            }
        }
        
        for (int i = 0; i < 4; i++) {
            int z = zero_locate + m[i];
            if (z < 0 || z >= 9 ) continue;
            if ( (i == 0 || i == 1) && (zero_locate/3 != z/3)) continue;
            
            swap(str[zero_locate],str[z]);
            q.push({stoi(str), value+1});
            swap(str[z],str[zero_locate]);
        }
        
    }
    return true;
    
}

int main(void) {
    
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    
    int now = 0;
    
    for (int i = 0; i <9; i++) {
        int value;
        cin >> value;
        now = now*10 + value;
    }
    
    if (BFS(now)) cout << -1;
    
    return 0;
}
