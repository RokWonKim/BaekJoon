import numpy as np

def identy_st(arr):			#각 배열들을 sort후 문자열로 만들어'123456789'인지 확인
    for i in range(0,9):		#전부 맞으면 1반환 하나라도 틀리면 0반환
        arr[i].sort()
        st = [str(x) for x in arr[i]]
        st = ''.join(st)
        if st != '123456789':
            return 0
    return 1

t = int(input())
for i in range(1,t+1):
    arr = list( list(map(int,input().split())) for _ in range(9) ) #9줄의 이중반복문 완성(전부 int로)
    arr_2 = list(zip(*arr))					#세로줄(열로 쪼개서 새로운 이중반복문 완성)
    arr_2 = [list(arr_2[x]) for x in range(9)]
    arr = np.array(arr)						#리스트 arr을 배열로 변경
    adsum = 0

    count = 0							#범위안에 있는 것들을 하나의 배열에 저장위해
    part_arr = np.empty([9,9], dtype = int)			#빈 9*9배열 int 형으로 만들기
    for col in range(0,9,3):					
        for row in range(0,9,3):
            array = arr[col:col+3, row:row+3]			#3*3만 따로 떼내어
            array = array.flatten()				#하나의 배열로 만들음
            part_arr[count] = array				#차곡차곡 쌓기
            count += 1

    adsum += identy_st(part_arr)				#3*3으로 9개인 part_arr
    adsum += identy_st(arr)					#행9줄인 arr
    adsum += identy_st(arr_2)					#열9줄인 arr_2 
								#각각의 리스트 및 배열에 9개 전부 123456789가 완성되면 1반환
    print("#%d" % i, end = ' ')
    if adsum == 3:
        print(1)
    else:
        print(0)
    

