#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;

int check[1 << (12*2)];
//같은 부호인지 확인
int confirm(int x) {
    if(!x) return 0; 
    return x > 0?1:-1;
}
// 현재 원판의 위치(봉 넘버)
int get(int now, int thing_num) {
    return (now >> (thing_num*2)) & 3;
}
// 원판을 옮겼을때의 값
// 원판의 봉 넘버를 바꿔줌
int set(int now, int thing_num, int next_bar) {
    return (now & ~(3 << (thing_num*2))) | (next_bar << (thing_num*2));
}

int BFS(int num, int begin, int end) {
    if (begin == end) return 0;

    queue<int> q;
    q.push(begin);
    q.push(end);
    check[begin] = 1;
    check[end] = -1;

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        int top[4] = {-1,-1,-1,-1};
        for (int thing = num-1; thing >= 0; thing--)
            top[get(now, thing)] = thing;
        
        //원판 옮기기 i에서 j로
        for (int i = 0; i < 4; i++) {
            //기둥에 원판이 없으면
            if (top[i] == -1) continue;
            for (int j = 0; j < 4; j++) {
                if (i == j) continue;
                //옮길 위치에 원판이 없거나
                //자신보다 높은 원판일 경우에만 옮길 수 있음
                if (top[j] == -1 || top[i] < top[j]) {
                    int next = set(now, top[i], j);
                    if (check[next] == 0) {
                        check[next] = check[now] + (check[now]<0?-1:1);;
                        q.push(next);
                    } 
                    //부호가 다른가?
                    else if (confirm(check[now]) != confirm(check[next]))
                        return abs(check[now]) + abs(check[next]) -1;
                }
            }
        }
    }

    return -1;
}

int main(void) {
    int T;
    scanf("%d", &T);
    while(T--) {
        memset(check, 0, sizeof(check));
        int N;
        int begin = 0;
        int end = 0;

        scanf("%d", &N);

        end = (1 << (N*2)) -1;
        for (int i = 0; i < 4; i++) {
            int num;
            scanf("%d", &num);
            
            for (int j = 0; j < num; j++) {
                int a;
                scanf("%d", &a);
                begin += (i << ((a-1)*2) );
            }
        }
        
        printf("%d\n", BFS(N, begin, end));
    }

    return 0;
}