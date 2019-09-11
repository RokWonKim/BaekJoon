#1979.어디_단어가_들어갈_수_있을까
t = int(input())
for i in range(1,t+1):
    N, K = map(lambda x:int(x), input().split(' ') )	#N,K를 입력
    arr = []
    print("#%d" % i , end = ' ')
    rcount = 0
    lcount = 0
    allcount = 0
    for j in range(N):					#각 행의 데이터를 입력 받아 arr로 합쳐 이중배열로 만듬
        part_arr = input().split(' ')
        arr += [part_arr]
    for j in range(N):					#K만큼만 1이 반복해야함 so, 1이 k만큼 반복되면 다음수를 본다
        rcount = 0							# 다음 인덱스가 존재하지 않거나 0이면 성공이므로 allcount를 증가
        lcount = 0							#rcount는 수평으로 연속 1이 나올때마다 증가 0이 나오는 초기화
        for z in range(N):				#lcount는 수직
            if arr[j][z] == '1':
                rcount += 1
                if rcount == K and (z == N-1 or arr[j][z+1] == '0'):
                    allcount += 1
            else:
                rcount = 0
                
            if arr[z][j] == '1':
                lcount += 1
                if lcount == K and (z == N-1 or arr[z+1][j] == '0'):
                    allcount += 1
            else:
                lcount = 0
    print(allcount)
