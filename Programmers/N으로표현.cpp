#include <string>
using namespace std;
int answer;
void express(int n, int number, int val, int now_num) {
    if (val > 8) return;
    if (now_num == number && val < answer) {
        answer = val;
        return;
    }
    int doublenum = 0;
    for (int i = 0; i < 8; i++) {
        doublenum = doublenum*10+n;
        express( n, number, val+1+i, now_num+doublenum );
        express( n, number, val+1+i, now_num-doublenum );
        express( n, number, val+1+i, now_num*doublenum );
        express( n, number, val+1+i, now_num/doublenum );
    }
}
int solution(int N, int number) {
    answer = 9;
    express(N,number,0,0);
    if (answer>8) return -1;
    return answer;
}
