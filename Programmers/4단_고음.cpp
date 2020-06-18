#include<cmath>

using namespace std;

int answer;

void solve(int n,int incre) {
    if (incre < 0 && n < pow(3, (-incre+1)/2 ) ) return;
    if (n == 1 && incre == 0) {
        answer++;
        return;
    }
    if (n <= 1)return;
    
    if ( n % 3 == 0 && incre <= -2) solve(n/3,incre+2);
    solve(n-1, incre-1);
}

int solution(int a) {
    answer = 0;
    
    solve(a,0);
    return answer;
}