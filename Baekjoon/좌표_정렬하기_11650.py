N = int(input())
arr = list(list(map(int, input().split())) for _ in range(N))
arr.sort(key=lambda x:x[1])     #두번째 원소로 정렬
arr.sort(key= lambda x:x[0])    #첫번째 원소로 정렬
for x in range(N):
    print("%d %d" % (arr[x][0], arr[x][1]) )

