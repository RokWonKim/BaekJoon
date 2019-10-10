t = int(input())			
for i in range(1, t+1):			
    Nk = input()
    N, k = map(lambda x:int(x), Nk.split())		#학생 수와 학생번호 받기
    arr = []
    index = 0
    print("#%d" % i, end = ' ')
    
    for j in range(N):									#학생 총점 및 학생번호를 하나의 리스트로 만들고 그 리스트를 arr에 추가 고로 2중 배열
        part_arr = input()
        part_arr = part_arr.split()
        part_arr = [int(x) for x in part_arr]
        addsum = part_arr[0]*0.35 + part_arr[1]*0.45+part_arr[2]*0.2	#총점 계산
        arr += [ [j+1,addsum] ]						#실제 학생 번호 및 총점을 리스트로 만들어 arr에 추가
    arr.sort(key=lambda point:point[1], reverse = True)		#학생의 총점으로 정렬
    
    for j in range(len(arr)):			#k가 몇번째에 존재하는지 를 index에 입력
        if arr[j][0] == k:
            index = j+1
            break
            
    if index <= int(N*0.3): print('A',end='')		#k가 총점으로 정렬된 리스트에서 상위 30%에 해당하면 A
    elif index <= int(N*0.6): print('B',end='')		#상위 60%면 B
    elif index <= int(N*0.9): print('C',end='')		#상위 90%면 C
    else:
        print('D0')			#하위 10%면 D0
        continue
        
    mode = index%int(N*0.3)		#+,-,0를 넣어줘야함 인덱스를 한 사이클로 나눠서 나머지를 저장함 
    std = int(N*0.3)			
    if mode == 0: print('-')		# 나머지가 0이란 것은 +,0,-순에서 - 끝에 해당
    elif mode <= int(std * (1/3)): print('+')	#상위 1/3은 +
    elif mode <= int(std * (2/3)): print('0')	#상위 3/2는 0
    else: print('-')										#상위 3/3은 -
