#1288.새로운_불면증_치료법
T = int(input())
for test_case in range(1, T + 1):
    N = int(input())
    arr = ['0']*10		#인덱스에 해당하는 수가 나오면 1로바꿈
    num = 1
    while num:
        sen = str(N*num)
        for i in range( len(sen) ):	#하나의 문자열로 바꿔서 인덱스 하나씩 검사
            arr[int(sen[i])] = '1'	#arr에 값에 해당하는것을 인덱스로 바뀌 '1'로 표시
        if ''.join(arr) == '1'*10:
            break;
        num += 1
    print(f'#{test_case} {N*num}')
