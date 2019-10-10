#1966.숫자를_정렬하자
t = int(input())
for i in range(1,t+1):
    N = int(input())
    arr = list(map(int,input().split() ) )
    arr.sort()
    print("#%d" % i, end = ' ')
    for x in arr:
        print(x,end = ' ') 
    print()
