N = int(input())
arr = [str(i) for i in range (0,N+1)]
for i in range (1, len(arr)):
    if arr[i].count('3') > 0 or arr[i].count('6') > 0 or arr[i].count('9') > 0:             # in을 사용 할 시 더편함 '3' in i ->i에 3이 있는지
        print('-'*arr[i].count('3')+'-'*arr[i].count('6')+'-'*arr[i].count('9'),end =' ')
    else:
        print(arr[i], end=' ')
