#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<map>

using namespace std;

int R,C;


char good[7] = {'|','-','+','1','2','3','4' };

// 동 서 남 북
int start[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

vector< pair<int,int> > m[300];

char arr[26][26];
bool check[26][26];
pair<int,int> start_city , end_city;

void BFS() {
    
    // 내가 온 좌표
    queue< pair<int,int> > q;
    
    int x = start_city.first;
    int y = start_city.second;
    for (int i = 0; i < 4; i++) {
        int new_x = x + start[i][0];
        int new_y = y + start[i][1];
        if (new_x >= 0 && new_x < R && new_y >= 0 && new_y < C) {
            if ( arr[new_x][new_y] != '.') {
                q.push({new_x,new_y});
                break;
            }
        }
        
    }
    
    while(!q.empty()) {
        int now_x = q.front().first;
        int now_y = q.front().second;
        
        q.pop();
        
        if (check[now_x][now_y] == true) continue;
        check[now_x][now_y] = true;
        
        if (arr[now_x][now_y] == '.') {
            
            bool angle[4] = {false, };
            
            //그 쪽에 있는 값이 이쪽과 뚫여 있는지를 확인
            for (int i = 0; i < 4; i++) {
                int new_x = now_x + start[i][0];
                int new_y = now_y + start[i][1];
                if (new_x >= 0 && new_x < R && new_y >= 0 && new_y < C) {
                    int v = arr[new_x][new_y];
                    if (i == 0){
                        if (v == '-' || v=='+' || v=='3' || v=='4')
                            angle[i] = true;
                    }
                    else if (i == 1){
                        if (v=='-' || v=='1' || v=='2' || v=='+')
                            angle[i] = true;
                    }
                    else if (i == 2){
                        if (v=='|' || v=='3' || v=='2' || v=='+')
                            angle[i] = true;
                        
                    }
                    else{
                        if (v=='|' || v=='1' || v=='4' || v=='+')
                            angle[i] = true;
                    }
                }
            }
            
            
            //0 1 2 3
            //동 서 남 북
            char ans;
            if (angle[0] && angle[1]) {
                if (angle[2]) ans = good[2];
                else ans = good[1];
            }
            else if (angle[2] && angle[3]) {
                if (angle[1]) ans = good[2];
                else ans = good[0];
            }
            else {
                if (angle[2]) {
                    if (angle[0]) ans = '1';
                    else ans = '4';
                }
                else{
                    if (angle[0]) ans = '2';
                    else ans = '3';
                }
            }
            
            cout << now_x+1 << ' ' << now_y+1 << ' ' << ans <<'\n';
            
            return;
        }
        else {
            int value = arr[now_x][now_y];
            for (int i = 0; i < m[value].size(); i++) {
                int new_x = now_x + m[value][i].first;
                int new_y = now_y + m[value][i].second;
                
                if (new_x >= 0 && new_x < R && new_y >= 0 && new_y < C)
                    q.push({new_x,new_y});
            }
        }
    }
}

int main(void) {
    
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    string str = "";
    
    cin >> R >> C;
    for(int i = 0; i < R; i++) {
        cin >> str;
        for (int j = 0; j < C; j++) {
            arr[i][j] = str[j];
            if (arr[i][j] == 'M') start_city={i,j};
            if (arr[i][j] == 'Z') end_city={i,j};
        }
    }
    
    m['|'].push_back({-1,0});
    m['|'].push_back({1,0});
    
    m['-'].push_back({0,-1});
    m['-'].push_back({0,1});
    
    m['+'].push_back({-1,0});
    m['+'].push_back({1,0});
    m['+'].push_back({0,-1});
    m['+'].push_back({0,1});
    
    m['1'].push_back({0,1});
    m['1'].push_back({1,0});
    
    m['2'].push_back({-1,0});
    m['2'].push_back({0,1});
    
    m['3'].push_back({-1,0});
    m['3'].push_back({0,-1});
    
    m['4'].push_back({0,-1});
    m['4'].push_back({1,0});
    
    BFS();
    
    return 0;
}
