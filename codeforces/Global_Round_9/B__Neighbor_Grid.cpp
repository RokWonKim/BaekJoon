#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;

int N,M;
int arr[300][300];
int answer[300][300];
int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

bool confirm() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] > answer[i][j])return false;
        }
    }
    return true;
}

int main(void) {
    
    int T;
    scanf("%d", &T);
    while(T--) {
        int zero = 0;
        scanf("%d %d", &N, &M);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                scanf("%d", &arr[i][j]);
                if (arr[i][j] == 0) zero++;
            }
        }

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                answer[i][j] = 4;

        for (int i = 0; i < N; i++) {
            answer[i][0] = 3;
            answer[i][M-1] = 3;
        }
        for (int i = 0; i < M; i++) {
            answer[0][i] = 3;
            answer[N-1][i] = 3;
        }
        
        answer[0][0] = 2;
        answer[0][M-1] = 2;
        answer[N-1][0] = 2;
        answer[N-1][M-1]= 2;

        if (zero == N*M) {
            printf("YES\n");
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++)
                    printf("%d ",arr[i][j]);
                printf("\n");
            }
        }
        else{
            if (confirm()) {
                printf("YES\n");
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < M; j++)
                        printf("%d ",answer[i][j]);
                    printf("\n");
                }
            }
            else printf("NO\n");
        }

    }

    return 0;
}