t = int(input())
for i in range(1, t+1):
    NM = input()
    N, M = map(lambda x:int(x), NM.split())
    arr = []								#배열로 전부 받을것
    print("#%d" % i ,end= ' ')
    for j in range(N):				#2차원 배열로 받기
        part_arr = input()
        part_arr = part_arr.split(' ')
        arr += [part_arr]
    addsum = []
    
    for j in range(0,N-M+1):	#행
        for z in range(0,N-M+1):	#열
            sum = 0							#M의 수만큼 처음수를 기준으로 행열을+M전까지 전부 더한 것
            for a in range(j, j+M):		#각 M*M의 합 구하기
                for b in range(z,z+M):
                    sum += int(arr[a][b])
            addsum += [sum]			#각 m*m을 addsum 배열에 저장
            
    addsum.sort()
    print(addsum[len(addsum)-1])
    
