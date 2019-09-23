#include<stdio.h>
#include<string.h>

//버킷 정렬로 사용 O(n)
int main(void) {
    
    int N,a;
    scanf("%d",&N);
    int arr[2001];	//범위가 -1000~1000임
    memset(arr,0,sizeof(arr));
    
    for(int i =0; i <N; i++) {
        scanf("%d", &a);
        arr[a+1000] = 1;	//수+1000을 인덱스로 가지는 곳에 1넣음
    }
    for(int i = 0; i < 2001; i++) {   //출력할땐 -1000해서
        if (arr[i] == 1)
            printf("%d\n",i-1000);
    }
    
    
    
    
    return 0;
}
