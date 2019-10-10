#include<stdio.h>
#include<string.h>

//버킷정렬	
int main(void) {
    int N,input;
    int arr[10001];
    memset(arr,0,sizeof(arr));
    
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++) {
        scanf("%d", &input);
        arr[input] += 1;
    }
    
    for(int i=1; i < 10001; i++) {
        for(int j = 0; j < arr[i]; j++)
            printf("%d\n", i);
    }
    return 0;
}
