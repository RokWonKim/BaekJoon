#include<iostream>

using namespace std;

int arr[10][10];
bool visit[10][10] = {false, };
int paper_num[6];
int ans;
int part_ans;

bool confirm(int x, int y, int value) {
    
    for (int i = x; i <= x + value; i++)
        for (int j = y; j <= y + value; j++)
            if (visit[i][j] == true || arr[i][j] == 0)
                return false;
    
    return true;
}

void reverse_fill(int x,int y,int value) {
    
    for (int i = x; i <= x+value; i++)
        for (int j = y; j <= y+value; j++)
            visit[i][j] = !visit[i][j];
    
}


void backtracking(int x, int y){
    
    if (x == 10)
        ans = min(ans, part_ans);
    else if (y == 10)
        backtracking(x+1, 0);
    else if (visit[x][y] == true || arr[x][y] == 0)
        backtracking(x, y+1);
    else {
        // arr[x][y]가 1인 경우 밖에 안남음
        for ( int i = 0; i <= 4; i++) {
            if ( paper_num[i+1] < 5 && x+i < 10 && y+i < 10 && confirm(x,y,i) ) {
                
                reverse_fill(x,y,i);
                paper_num[i+1]++;
                part_ans++;
                
                backtracking(x,y + i);
                
                reverse_fill(x,y,i);
                paper_num[i+1]--;
                part_ans--;
            }
        }
    }
    
}

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    ans = 100000;
    
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            cin >> arr[i][j];

    backtracking(0,0);
    if (ans == 100000) cout << -1 << '\n';
    else cout << ans << '\n';
    
    return 0;
}
