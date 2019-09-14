#1961.숫자_배열_회전
for i in range(int(input())):
    N = int(input())
    arr = list(list(map(int,input().split() ) ) for _ in range(N) )
    print(f'#{i+1}')			#ㄴ이차원 배열 받기
    for j in range(N):
        for z in range(N):		#90도 돌릴때 출력
            print(arr[N-z-1][j],end ='')	
        print(end=' ')
        for z in range(N):		#180도 돌릴때 출력
            print(arr[N-j-1][N-z-1],end='')
        print(end=' ')
        for z in range(N):		#270도 돌릴때 출력
            print(arr[z][N-j-1],end='')
        print()
            
