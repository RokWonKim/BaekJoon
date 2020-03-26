#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int arr[51][51];
bool check[51][51] = {false, };
int m[8][2] = { {1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1} };

int main(void) {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    while(1) {

        int num = 0;
        int a,b;

        cin >> a >> b;

        if (a == 0 && b == 0)
            break;

        for (int i = 0; i < b; i++)
            for (int j = 0; j < a; j++){
                cin >> arr[i][j];
                check[i][j] = false;
            }


        for (int i = 0; i < b; i++) {
            for (int j = 0; j < a; j++) {
                if (check[i][j] == false && arr[i][j] == 1) {
                    check[i][j] = true;
                    queue< pair<int,int> > q;
                    q.push({i,j});
                    num++;
                    
                    while(!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        for (int z = 0; z < 8; z++) {
                            int new_x = x + m[z][0];
                            int new_y = y + m[z][1];

                            if ( new_x >= 0 && new_x < b && new_y >=0 && new_y < a) {
                                if (arr[new_x][new_y] == 1 && check[new_x][new_y] == false) {
                                    check[new_x][new_y] = true;
                                    q.push({new_x,new_y});
                                }
                            }
                        }
                    }

                }
            }
        }
        cout << num <<'\n';

    }

    return 0;
}