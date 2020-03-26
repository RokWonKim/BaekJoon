#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

int ans;
vector< vector<int> > arr;
int m[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

bool solve() {
    bool check[12][6];
    vector< vector<int> > c(12, vector<int>(6));

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            c[i][j] = arr[i][j];
            check[i][j] = false;
        }
    }

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {

            if (c[i][j] == 0)
                check[i][j] = true;
            else if (check[i][j] == false) {
                check[i][j] = true;
                int value = c[i][j];
                int num = 0;

                queue< pair<int,int> > q;
                vector< pair<int,int> > diss;
                
                q.push({i,j});
                diss.push_back({i,j});
  
                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    num++;
                    q.pop();

                    for (int z = 0; z < 4; z++) {
                        int new_x = x+m[z][0];
                        int new_y = y+m[z][1];
           
                        if (new_x >= 0 && new_x < 12 && new_y >=0 && new_y < 6) {
                            if (c[new_x][new_y] == value && check[new_x][new_y]==false) {
                                check[new_x][new_y] = true;
                                q.push({new_x, new_y});
                                diss.push_back({new_x, new_y});
                            }
                        }
                    }

                }

                if (num >= 4) {
                    for (int z = 0; z < diss.size(); z++) {
                        int x = diss[z].first;
                        int y = diss[z].second;
                        c[x][y] = 0;
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < 6; i++) {
        int count = 0;
        for (int j = 11; j >= 0; j--) {
            if(c[j][i] == 0)
                count++;
            else {
                if (count != 0) {
                    c[j+count][i] = c[j][i];
                    c[j][i] = 0;
                }
            }
        }
    }

    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 6; j++)
            if (c[i][j] != arr[i][j]) {
                arr = c;
                return true;
            }       

    return false;
}


int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str = "";

    for (int i = 0; i < 12; i++) {
        cin >> str;
        vector<int> a;
        for (int j = 0; j < 6; j++) {
            if (str[j] == '.')
                a.push_back(0);
            else if (str[j] == 'R')
                a.push_back(1); 
            else if (str[j] == 'G')
                a.push_back(2);
            else if (str[j] == 'B')
                a.push_back(3);
            else if (str[j] == 'P')
                a.push_back(4); 
            else if (str[j] == 'Y')
                a.push_back(5);
        }
        arr.push_back(a);
    }

    while(solve()) {
        ans++;
    }
    
    cout << ans;

    return 0;
}