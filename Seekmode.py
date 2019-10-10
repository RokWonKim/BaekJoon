t = int(input())
max = 0  # 가장 빈도수가 높으면서 가장 큰값
maxcount = 0  # 빈도수
for i in range(1, t + 1):
    print("#%d" % i, end=' ')
    tnum = input()
    arr = input().split()
    arr = [int(x) for x in arr]  # 1000개 입력 받은것들 전부 숫자로 바꿔주기
    point = [0] * 101  # arr에서 수가 나올 때 point[수] 에 빈도수를 하나씩 올려주기
    for j in range(0, len(arr)):
        point[arr[j]] += 1
        if point[arr[j]] > maxcount:  # 기존 최대 빈도 수보다 현재 수의 빈도수가 많을 시 바꿔줌
            max = arr[j]
            maxcount = point[arr[j]]
        elif point[arr[j]] == maxcount:  # 이때까지 최대 빈도수와 같은 빈도수를 가지고 있다면 더 큰 수를 max에 저장
            if max < arr[j]:
                max = arr[j]
    print(max)
    max = 0
    maxcount = 0
