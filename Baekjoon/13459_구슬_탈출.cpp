#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

int N, M;
int arr[11][11];
pair<int,int> red, blue;
vector<int> direct;

pair<int,int> now_red;
pair<int,int> now_blue;


int left_move(int rx, int ry, int bx, int by) {
    
    bool red_flag = false;
    bool blue_flag = false;
    
    
    //by부터
    if (ry > by) {
        int i;
        int j;
        
        for (i = 1; i < 10; i++) {
            now_blue.second = by-i;
            
            if (arr[bx][by-i] == '#' ) {
                now_blue.second++;
                break;
            }
            else if (by-i > -1 && arr[bx][by-i] == 'O') {
                blue_flag = true;
                break;
            }
        }
        
        for (j = 1; j < 10; j++) {
            now_red.second = ry-j;
            
            if (arr[rx][ry-j] == '#' ) {
                now_red.second++;
                break;
            }
            if (ry-j > -1 && arr[rx][ry-j] == 'O') {
                red_flag = true;
                break;
            }
            else if ( ry-j > -1 && (rx == bx && ry-j == now_blue.second) ) {
                now_red.second++;
                break;
            }
            
        }
        
    }
    else{
        int i;
        int j;
        
        for (j = 1; j < 10; j++) {
            now_red.second = ry-j;
            
            if (arr[rx][ry-j] == '#' ) {
                now_red.second++;
                break;
            }
            else if (ry-j > -1 && arr[rx][ry-j] == 'O') {
                red_flag = true;
                break;
            }
        }
        //cout << now_red.second << "  ";
        
            
        for (i = 1; i < 10; i++) {
            now_blue.second = by-i;
            //cout << by-i << ' ';
            
            if (arr[bx][by-i] == '#' ) {
                now_blue.second++;
                break;
            }
            else if (by-i > -1 && arr[bx][by-i] == 'O') {
                blue_flag = true;
                break;
            }
            else if ( by-i > -1 && (rx == bx && by-i == now_red.second) ) {
                now_blue.second++;
                break;
            }
        }
        
       
        //cout << red_flag << blue_flag << "Dfdf"<<'\n';
    }
    
    if (blue_flag)
        return 0;
    else if (red_flag) {
        //cout << now_red.first << now_red.second << "   " << now_blue.first << ' '<< now_blue.second <<'\n';
        return 1;
    }
    else return 2;
}


int right_move(int rx, int ry, int bx, int by) {
    bool red_flag = false;
    bool blue_flag = false;
    
    // by부터
    if (ry < by) {
        int i;
        int j;
        
        for (i = 1; i < 10; i++) {
            now_blue.second = by+i;
            
            if (arr[bx][by+i] == '#' ) {
                now_blue.second--;
                break;
            }
            else if (by+i < M && arr[bx][by+i] == 'O') {
                blue_flag = true;
                break;
            }
        
        }
        
        
        for (j = 1; j < 10; j++) {
            now_red.second = ry+j;
            
            if (arr[rx][ry+j] == '#' ) {
                now_red.second--;
                break;
            }
            
            if (ry+j < M && arr[rx][ry+j] == 'O') {
                red_flag = true;
                break;
            }
            else if ( ry+j < M && (rx == bx && ry+j == now_blue.second) ) {
                now_red.second--;
                break;
            }
          
            
          
        }
        
        
        
    }
    else{
        int i;
        int j;
        
        for (j = 1; j < 10; j++) {
            now_red.second = ry+j;
            
            if (arr[rx][ry+j] == '#' ) {
                now_red.second--;
                break;
            }
            else if (ry+j < M && arr[rx][ry+j] == 'O') {
                red_flag = true;
                break;
            }
            
        }
        
        
        for (i = 1; i < 10; i++) {
            now_blue.second = by+i;
            
            if (arr[bx][by+i] == '#' ) {
                now_blue.second--;
                break;
            }
            
            if (by+i < M && arr[bx][by+i] == 'O') {
                blue_flag = true;
                break;
            }
            else if ( by+i < M && (rx == bx && by+i == now_red.second) ) {
                now_blue.second--;
                break;
            }
        }
    }
    
    
    
    if (blue_flag)
        return 0;
    else if (red_flag)
        return 1;
    else return 2;
    
}
int top_move(int rx, int ry, int bx, int by) {
    
    bool red_flag = false;
    bool blue_flag = false;
    
    //bx부터
    if (rx > bx) {
        int i;
        int j;
        
        for (i = 1; i < 10; i++) {
            now_blue.first = bx-i;
            
            if (arr[bx-i][by] == '#' ) {
                now_blue.first++;
                break;
            }
            else if (arr[bx-i][by] == 'O') {
                blue_flag = true;
                break;
            }
        }
        
        for (j = 1; j < 10; j++) {
            now_red.first = rx-j;
            
            if (arr[rx-j][ry] == '#' ) {
                now_red.first++;
                break;
            }
            else if ( arr[rx-j][ry] == 'O') {
                red_flag = true;
                break;
            }
            else if ( ry == by && rx-j == now_blue.first ) {
                now_red.first++;
                break;
            }
                
        }
        
        
        
    }
    else{
        int i;
        int j;
        
        for (j = 1; j < 10; j++) {
            now_red.first = rx-j;
            
            if (arr[rx-j][ry] == '#' ) {
                now_red.first++;
                break;
            }
            else if (arr[rx-j][ry] == 'O') {
                red_flag = true;
                break;
            }
        }
        
        for (i = 1; i < 10; i++) {
            now_blue.first = bx-i;
            
            if (arr[bx-i][by] == '#' ) {
                now_blue.first++;
                break;
            }
            else if ( arr[bx-i][by] == 'O') {
                blue_flag = true;
                break;
            }
            else if (ry == by && bx-i == now_red.first) {
                now_blue.first++;
                break;
                
            }

            
        }
    }
    //cout << "top " << now_blue.first << now_blue.second << '\n';
    
    
    if (blue_flag)
        return 0;
    else if (red_flag)
        return 1;
    else return 2;
}


int down_move(int rx, int ry, int bx, int by) {
    
    bool red_flag = false;
    bool blue_flag = false;
   
   //bx부터
   if (rx < bx) {
       int i;
       int j;
       
       for (i = 1; i < 10; i++) {
           now_blue.first = bx+i;
           
           if (arr[bx+i][by] == '#' ) {
               now_blue.first--;
               break;
           }
           else if (arr[bx+i][by] == 'O') {
               blue_flag = true;
               break;
           }
    
       }
       
       
       for (j = 1; j < 10; j++) {
           now_red.first = rx+j;
           
           if (arr[rx+j][ry] == '#' ) {
               now_red.first--;
               break;
           }
           
           if (arr[rx+j][ry] == 'O') {
               red_flag = true;
               break;
           }
           else if ( ry == by && rx+j == now_blue.first ) {
               now_red.first--;
               break;
           }
       }
       
       
       
   }
   else{
       int i;
       int j;
       
       for (j = 1; j < 10; j++) {
           now_red.first = rx+j;
           
           if (arr[rx+j][ry] == '#' ) {
               now_red.first--;
               break;
           }
           else if (rx+j < N && arr[rx+j][ry] == 'O') {
               red_flag = true;
               break;
           }
           
  
       }
       
       for (i = 1; i < 10; i++) {
           now_blue.first = bx+i;
           
           if (arr[bx+i][by] == '#' ) {
               now_blue.first--;
               break;
           }
           if (arr[bx+i][by] == 'O') {
               blue_flag = true;
               break;
           }
           else if ( ry == by && bx+i == now_red.first ) {
               now_blue.first--;
               break;
           }
           
       }
   }
   
   
   
   if (blue_flag)
       return 0;
   else if (red_flag)
       return 1;
   else return 2;
}



bool BFS() {
    
    now_red.first = red.first;
    now_red.second = red.second;
    
    now_blue.first = blue.first;
    now_blue.second = blue.second;
    
    for (int i = 0; i < direct.size(); i++) {
        int value = direct[i];
        int rx = now_red.first;
        int ry = now_red.second;
        
        int bx = now_blue.first;
        int by = now_blue.second;
        
        int ans = 0;
        
        //왼
        if ( value == 0 ) {
            ans = left_move(rx,ry,bx,by);
        }
        //위
        else if ( value == 1 ) {
            ans = top_move(rx,ry,bx,by);
        }
        //우
        else if ( value == 2) {
            ans = right_move(rx,ry,bx,by);
        }
        //아래
        else {
            ans = down_move(rx,ry,bx,by);;
        }
        
        if (ans == 1) {
            //cout <<  "index "<<i << '\n' ;
            return true;
        }
        else if (ans == 0) return false;
        
    }
    
    
    
    
    return false;
}

// 왼 위 우 아래 0,1,2,3
//갯수, 전 방향
void backtracking(int num, int pre_direct ) {
    
    if (num == 10) {
        if (BFS()) {
            cout << 1;
            //cout << now_red.first << ' ' << now_red.second << '\n';
            //for (int i = 0; i < 10; i++)
            //    cout << direct[i] <<' ' << '\n';
            exit(0);
        }
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        if (num == 0) {
            direct.push_back(i);
            backtracking(num+1, i);
            direct.pop_back();
        }
        else {
            if ( i == pre_direct || i == ((pre_direct+2)%4) ) continue;
            
            direct.push_back(i);
            backtracking(num+1, i);
            direct.pop_back();
            
        }
        
        
    }
}

int main(void) {
    
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    string str;
    
    for (int i = 0; i < N; i++) {
        cin >> str;
        for (int j = 0; j < M; j++) {
            arr[i][j] = str[j];
            if (arr[i][j] == 'R')
                red = {i,j};
            if (arr[i][j] == 'B')
                blue = {i,j};
        }
    }
    
    backtracking(0,-1);
    
    cout << 0;
    
    return 0;
}
