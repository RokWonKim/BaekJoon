#1979.시각_덧셈
t = int(input())
for i in range(1,t+1):
    arr = tuple(map(int, input().split() ) )		#입력 값 다 인트로 바꿔서 arr에 튜플로 저장
    hour = 0													#시간저장
    minute = 0												#분 저장
    for j in range(0,len(arr) ):						#0과 홀수는 시간에,짝수는 분에 저장
        if j == 0 or j %2 == 0: hour += arr[j]
        else: minute += arr[j]
    hour += minute//60									#60분 넘으면 60분을 1시간으로 바꿔 넣음
    if hour > 12: hour -= 12							# 시간이 12를 넘으면 12시간을 빼서 넣음

    print("#{} {} {}".format(i,hour,minute%60) )
