//1285.아름이의_돌_던지기
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void) {
    int T;
    scanf("%d", &T);
    for (int i = 1; i < T+1; i++) {
        int N;
        scanf("%d", &N);
        int min = 0;
        int count = 1;
        int *arr = (int *)malloc(sizeof(int)*N);
        for (int j = 0; j < N; j++) {
            scanf("%d", &arr[j]);
            arr[j] = abs(arr[j]);
            if (j==0)
                min = arr[j];
            else if (min > arr[j] ) {
                min = arr[j];
                count = 1;
            }
            else if (min == arr[j])
                count++;
        }
        printf("#%d %d %d\n",i,min,count);   
    }
 return 0;   
}
