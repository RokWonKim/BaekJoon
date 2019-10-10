#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//merge정렬 사용 O(nlog n)
void merge(int* sorted, int* list, int left, int mid, int right) {
    int a,b,c,d;
    a = left;
    c = left;
    b = mid+1;
    
    while(a<=mid && b<=right) {     //왼쪽과 우측을 비교하여 작은걸 때려넣음
        if(list[a] <= list[b])
            sorted[c++] = list[a++];
        else
            sorted[c++] = list[b++];
    }

    if (a > mid) {		//좌측과 우측을 비교 후 남은 쪽의 수를 
        for(d=b; d<=right; d++) //다음 인덱스에 다 넣음
            sorted[c++] = list[d];
    }
    else {
        for(d=a; d<=mid; d++)
            sorted[c++] = list[d];
    }

    for(d=left; d<=right; d++) //위의 것을 sorted(빈배열)에 저장했으므로
        list[d] = sorted[d];   //실제 배열인 list에 옮겨 넣음(배열된 상태를)
}

void merge_sort(int* sorted, int* list, int left, int right) {
    if (left<right){		//원소가 하나가 되면 left==right이므로 돌아감
        int mid = (left+right)/2;	// 반으로 쪼갠 인덱스
        merge_sort(sorted, list, left, mid);	// 반으로쪼갠 좌측을 다시 재귀
        merge_sort(sorted, list, mid+1, right);	// 우측을 다시 재귀
        merge(sorted, list, left, mid, right);	// 좌측과 우측을 합쳐 정렬
    }
}

int main(void) {
    int N;
    scanf("%d", &N);

    int *arr = (int*)malloc(sizeof(int)*N);	//실제 배열이 저장되는 곳
    int *sorted = (int*)malloc(sizeof(int)*N);	//정렬된 배열을 잠시 저장하는 곳
    memset(sorted,0,sizeof(sorted));
    
    for (int i =0; i < N; i++)
        scanf("%d", &arr[i]);
    
    merge_sort(sorted,arr, 0, N-1);

    int num = 0;
    for(int i =0; i <N; i++) {
        printf("%d\n", arr[i]);   
    }
    
    free(arr);
    free(sorted);

    return 0;
}

