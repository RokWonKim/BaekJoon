for i in range(int(input())):
    A, B = map(int,input().split() )
    arr1 = list(map(int,input().split() ) )
    arr2 = list(map(int,input().split() ) )
    arrsum = []
    if A>B:
        for j in range(A-B+1):	#긴 배열의 인덱스를 1씩 증가하면 곱한 값의 합을저장
            arrsum += [sum([arr1[z+j]*arr2[z] for z in range(B)])]
    else:
        for j in range(B-A+1):
            arrsum += [sum([arr1[z]*arr2[z+j] for z in range(A)])]
    print(f'#{i+1} {max(arrsum)}')
                
