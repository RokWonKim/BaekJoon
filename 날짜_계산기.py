#1948.날짜_계산기
for i in range(int(input())):
    arr = list(map(int,input().split()))
    day = [31,28,31,30,31,30,31,31,30,31,30,31]
    answer = 0
    if arr[0] == arr[2]:		#같은 month일 경우 날짜만 더해주기
        answer = arr[3]-arr[1]+1	
    else:				#다른 month일 경우 그 사이의 month에 해당하는 daye더해줌
        gap = arr[2]-arr[0]-1		
        for z in range(gap):
            answer += day[arr[0]+z]
        answer += day[arr[0]-1]-arr[1]+1+ arr[3]	#index0에 해당하는 날은 해당day에서 빼서 더해주고
    print(f'#{i+1} {answer}')				#index2에 해당하는 날은 그냥 더해줌
