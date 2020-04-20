#include<iostream>
#include<queue>
#include<vector>
#include<string>

using namespace std;

int N,M;
int arr[1001][1001];
int print_arr[1001][1001];
bool check[1001][1001];
int m[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

bool possible(int x, int y) {
    if (x >= 0 && x < N && y >= 0 && y < M)
        return true;
    return false;
}

void BFS(int a, int b) {
    int zero_count = 0;
    queue< pair<int,int> > q;
    vector< pair<int,int> > meet_deter;
    q.push({a,b});
    
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        int &value = arr[x][y];
        q.pop();
        
        if (check[x][y] == true) continue;
        check[x][y] = true;
        
        if (value == 0)
            zero_count++;
        else {
            meet_deter.push_back({x,y});
            continue;
        }
        
        for (int i = 0; i < 4; i++) {
            int new_x = x + m[i][0];
            int new_y = y + m[i][1];
            
            if ( possible(new_x, new_y) )
                q.push({new_x,new_y});
        }
    }
    
    for (int i = 0; i < meet_deter.size(); i++) {
        int x = meet_deter[i].first;
        int y = meet_deter[i].second;
        
        print_arr[x][y] = (print_arr[x][y] + zero_count) %10;
        check[x][y] = false;
    }
    
}

int main(void) {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    string str;
    for (int i = 0; i < N; i++) {
        cin >> str;
        for (int j = 0; j < M; j++) {
            arr[i][j] = str[j] - '0';
            if (arr[i][j] == 1)
                print_arr[i][j] = 1;
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (check[i][j] == false && arr[i][j] == 0)
                BFS(i,j);
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << print_arr[i][j];
        }
        cout << '\n';
    }
    
    return 0;
}
