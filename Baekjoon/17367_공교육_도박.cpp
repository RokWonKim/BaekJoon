
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
double dp[1002][7][7][7];
long long answer;

double calc(int a, int b, int c) {
    if (a == b && b == c) return 10000+a*1000;
    else if (a == b) return 1000+a*100;
    else if (b == c) return 1000+b*100;
    else if (a == c) return 1000+a*100;
    else return max(a,max(b,c))*100;

}

double solve(int index, int a, int b, int c) {
    if (index == N) return calc(a,b,c);

    double &value = dp[index][a][b][c];
    if (value != -1) return value;

    value = 0;
    for (int i = 1; i <= 6; i++)
        value += solve(index+1, b,c,i);

    value/= 6;
    if (index >= 3) value = max(value, calc(a,b,c));

    return value;
}

int main(void) {

    fill(&dp[0][0][0][0], &dp[1001][6][6][7], -1);

    scanf("%d", &N);
    printf("%.7lf\n", solve(0, 0, 0, 0));
    
    return 0;
}