#간단한 369게임 1926
N = int(input())
arr = [str(i) for i in range (0,N+1)]
for i in range (1, len(arr)):
    if arr[i].count('3') > 0 or arr[i].count('6') > 0 or arr[i].count('9') > 0:             # in을 사용 할 시 더편함 '3' in i ->i에 3이 있는지
        print('-'*arr[i].count('3')+'-'*arr[i].count('6')+'-'*arr[i].count('9'),end =' ')
    else:
        print(arr[i], end=' ')

#for문 안에서 3이나 6이나 9가 한문장(ex) "36")(2번째 줄에서 수를 전부 문자열로 리스트에  저장함)
#3 6 9가 하나 이상 있을 시 있는 만큼 출력함
