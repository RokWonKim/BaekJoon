#include<iostream>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

int N;
vector< vector< pair<int,int> > > island;
int arr[101][101];
bool check[101][101];
int m[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int land_num = 0;

void BFS(int a, int b) {
    queue< pair<int,int> > q;
    vector<pair<int,int> > v;
    q.push({a,b});
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if (check[x][y] == true) continue;
        
        check[x][y] = true;
        v.push_back({x,y});
        
        for(int i = 0; i < 4; i++) {
            int new_x = x + m[i][0];
            int new_y = y + m[i][1];
            
            if (new_x >= 0 && new_x < N && new_y >=0 && new_y < N)
                if (arr[new_x][new_y] == 1 && check[new_x][new_y]==false)
                    q.push({new_x,new_y});
        }
    }
    
    island.push_back(v);
    land_num++;
}

int main(void) {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    
    int ans = 100000;
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (check[i][j] == false && arr[i][j] == 1)
                BFS(i, j);
    
    
    for (int i = 0; i < land_num-1; i++)
        for (int j = i+1; j < land_num; j++)
            for(pair<int,int> a : island[i])
                for(pair<int,int> b : island[j])
                    ans = min(ans, abs(a.first-b.first) + abs(a.second-b.second)-1 );

                    
    cout << ans << '\n';
    
    return 0;
}
