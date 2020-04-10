#include<iostream>
#include<string>
#include<algorithm>
#include<string.h>
#include<vector>
#include<map>
#include<queue>

using namespace std;

struct info {
    int x;
    int y;
    int weight;
};

int N, M;
int matrix[51][51];
bool visit[51][51];
int union_find[253];
int tree_rank[253];
int moving[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int ans_value;

map<pair<int,int>, int> m;
vector<info> ans;
vector< pair<int,int> > key_exist;

bool compare(const info& a, const info& b ) {
    return a.weight < b.weight;
}

int find(int x) {
    if (x == union_find[x])
        return x;
    return union_find[x] = find(union_find[x]);
}

bool merge(int x, int y, int value) {
    x = find(x);
    y = find(y);
    
    if (x == y) return false;
    
    union_find[x] = y;
    tree_rank[y] += tree_rank[x];
    ans_value += value;
    
    if (tree_rank[y] == M+1)
        return true;
    
    return false;
}


void BFS(pair<int,int> p) {
    
    memset(visit, false, sizeof(visit));
    
    queue< pair<int,pair<int,int>> > q;
    q.push({0, p});
    
    bool start = false;
    while(!q.empty()) {
        int x = q.front().second.first;
        int y = q.front().second.second;
        int value = q.front().first;
        q.pop();
        
        if (visit[x][y] == true) continue;
        if (matrix[x][y] == 3 && start == true) {
            ans.push_back({m[p] ,m[{x,y}],value});
            visit[x][y] = true;
            continue;
        }
        start = true;
        visit[x][y] = true;
        
        for (int i = 0; i < 4; i++) {
            int next_x = x + moving[i][0];
            int next_y = y + moving[i][1];
            
            if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N ) {
                if ( matrix[next_x][next_y] != 1)
                    q.push({value+1, {next_x, next_y}});
            }
                
        }
    }
    
}


int main(void) {
    
    ios_base:: sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    string str = "";
    
    int k_num = 0;
    
    for (int i = 0; i < N; i++) {
        cin >> str;
        for (int j = 0; j < N; j++) {
            
            if (str[j] == '1')
                matrix[i][j] = 1;
            else if (str[j] == 'K' || str[j] == 'S') {
                matrix[i][j] = 3;
                m[{i,j}] = k_num++;
                key_exist.push_back({i,j});
            }
            else
                matrix[i][j] = 0;
        }
    }
    
    for (int i = 0; i < key_exist.size(); i++) {
        BFS( key_exist[i] );
        union_find[i] = i;
        tree_rank[i] = 1;
    }
    
    bool flag = false;
    sort(ans.begin(), ans.end(), compare);
    
    for (int i = 0; i < ans.size(); i++) {
        info a = ans[i];
        
        if (merge(a.x, a.y, a.weight)) {
            flag = true;
            cout << ans_value;
            break;
        }
    }
    if (flag == false)
        cout << -1;
    
    
    return 0;
}
