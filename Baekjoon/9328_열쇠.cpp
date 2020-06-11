#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cstring>

using namespace std;

int n,m;
string str;
int arr[101][101];
bool check[101][101];
int key[257];
int mov[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
queue<int> get_key;
vector<pair<int,int> > cap_locate[256];
int ans;

bool possible(int x, int y ) {
    if (x >= 1 && x <= n && y >= 1 && y <= m)
        return true;
    return false;
}

void BFS(int a, int b) {
    
    queue<pair<int,int>> q;
    q.push({a,b});
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        int &value = arr[x][y];
        q.pop();
        
        if (check[x][y] == true)continue;
        check[x][y] = true;
        
        if (value == '*') continue;
        else if (value >= 'A' && value <= 'Z') {
            if (key[value + 32] == 1)
                value = '.';
            else {
                cap_locate[value].push_back({x,y});
                continue;
            }
        }
        else if (value >= 'a' && value <= 'z') {
            if (key[value] == 1)
                value = '.';
            else {
                key[value] = 1;
                get_key.push(value);
                value = '.';
            }
        }
        else if (value == '$')
            ans++;
        
        for (int i = 0; i < 4; i++) {
            int new_x = x + mov[i][0];
            int new_y = y + mov[i][1];
            
            if ( possible(new_x, new_y) ) {
                q.push({new_x,new_y});
            }
        }
    }
    
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        
        for (int i = 65; i <= 90; i++)
            cap_locate[i].clear();
        memset(check, false, sizeof(check));
        memset(key, 0, sizeof(key));
        ans = 0;
        
        cin >> n >> m;
        
        string s;
        
        for (int i = 1; i <= n; i++) {
            cin >> s;
            for (int j = 1; j <= m; j++)
                arr[i][j] = s[j-1];
        }
                
        cin >> str;
        if (str[0] != '0') {
            for (int i = 0; i < str.size(); i++) {
                key[str[i]] = 1;
                get_key.push(str[i]);
            }
        }
        
        for (int i = 1; i <= n; i++) {
            if (i == 1 || i == n) {
                for ( int j = 1; j <= m; j++) {
                    if (check[i][j] == false ) BFS(i,j);
                }
            }
            else {
                if (check[i][1] == false) BFS(i,1);
                if (check[i][m] == false) BFS(i,m);
            }
        }
        
        while(!get_key.empty() ) {
            int k = get_key.front();
            get_key.pop();
            
            for (pair<int,int> p : cap_locate[k-32]) {
                int x = p.first;
                int y = p.second;
                if ( arr[x][y] != '.') {
                    check[x][y] = false;
                    BFS(x,y);
                }
            }
            
        }
        
        cout << ans <<'\n';
    }
    return 0;
}
