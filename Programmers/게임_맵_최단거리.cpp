#include<vector>
#include<queue>

using namespace std;

struct info{
    int x;
    int y;
    int num;
};

bool visit[100][100];
int d[4][2] = {{0,1},{0,-1}, {1,0}, {-1,0}};

int solution(vector<vector<int> > maps)
{
    int answer = -1;
    int row_s = maps.size();
    int col_s = maps[0].size();
    
    queue<info> q;
    q.push({0,0,1});
    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int num = q.front().num;
        q.pop();
        
        if(visit[x][y]) continue;
        visit[x][y] = true;
        if(x == row_s-1 && y == col_s-1) return num;
        
        for (int i = 0; i < 4; i++) {
            int next_x = x + d[i][0];
            int next_y = y + d[i][1];
            if (next_x >= row_s || next_x < 0 || next_y >= col_s || next_y < 0) continue;
            if (maps[next_x][next_y] == 1)
                q.push({next_x,next_y,num+1});
        }
    }
    
    return answer;
}