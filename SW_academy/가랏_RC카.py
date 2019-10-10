#1940.가랏_RC카!
for i in range(int(input())):
    N = int(input())
    arr = list( list( map(int,input().split()) ) for _ in range(N))
    now = 0
    sum = 0
    for j in range(N):
        if arr[j][0] == 1:
            now += arr[j][1]
        elif arr[j][0] == 2:
            now -=arr[j][1]
        if now < 0:
            now = 0
        sum += now
    print(f'#{i+1} {sum}')
