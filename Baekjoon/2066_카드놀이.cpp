#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#define f(z) for(z = 0; z < 5; z++)

using namespace std;

char arr[9][5];
double dp[5][5][5][5][5][5][5][5][5];

double solve(int* part) {
    
    if (part[0]+part[1]+part[2]+part[3]+part[4]+part[5]+part[6]+part[7]+part[8] == 0)
        return 1;
    
    double &value = dp[part[0]][part[1]][part[2]][part[3]][part[4]][part[5]][part[6]][part[7]][part[8]];
    if (value != -1) return value;

    value = 0;
    int count = 0;
    for (int x = 0; x < 9; x++) {
        if (part[x] == 0) continue;
        for (int y = x+1; y < 9; y++) {
            if (part[y] == 0) continue;
            if (arr[x][part[x]] == arr[y][part[y]]) {
                count++;
                part[y]--;
                part[x]--;
                value += solve(part);
                part[y]++;
                part[x]++;
            }
        }
    }
    if (count != 0)
        value = value/count;

    return value;
}

int main(void) {

    int a,b,c,d,e,f,g,h,i;
    a=b=c=d=e=f=g=h=i=0;
    f(a)f(b)f(c)f(d)f(e)f(f)f(g)f(h)f(i) dp[a][b][c][d][e][f][g][h][i] = -1;
    
    for (int x = 0 ; x < 9; x++) {
        for (int y = 1; y < 5; y++) {
            char c[3];
            scanf(" %s", c);
            arr[x][y] = c[0];
        }
    }    
    
    int part[9] = {4,4,4,4,4,4,4,4,4};
    printf("%.7lf\n", solve(part) );

    return 0;
}