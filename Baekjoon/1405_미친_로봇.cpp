#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

int N;

// 0 1 2 3
long double east, west, south, north;
long double percent;

int check[35][35];
vector<long double> route;

void backtracking(int x, int y, int direct) {

    if (check[x][y] == 1)
        return;

    if (route.size() == N) {
        long double part = 1;

        for (int i = 0; i < N; i++)
            part *= route[i];

        percent += part;
        return;
    }
    
    check[x][y] = 1;
    for(int i = 0; i < 4; i++) {
        if (i == direct)
            continue;

        if ( i == 0 ){
            route.push_back(east);
            backtracking(x,y+1, 1);
        } 
        else if ( i == 1 ) {
            route.push_back(west);
            backtracking(x,y-1, 0);
        }   
        else if ( i == 2 ) {
            route.push_back(south);
            backtracking(x+1,y, 3);
        }
        else {
            route.push_back(north);
            backtracking(x-1,y, 2);
        }
        
        route.pop_back();
    }
    check[x][y] = 0;
}


int main(void) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(14);

    memset(check, 0, sizeof(check));
    percent = 0.0;

    cin >> N;
    cin >> east >> west >> south >> north;

    east /= 100;
    west /= 100;
    south /= 100;
    north /= 100;

    backtracking(15, 15, -1);

    cout << percent << '\n';

    return 0;
}