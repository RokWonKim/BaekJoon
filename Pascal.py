import copy

t = int(input())
arr = list()
pre_arr = list()
for i in range(1, t + 1):
    N = int(input())
    print("#{}".format(i))
    for j in range(1, N + 1):
        pre_arr = arr.copy()    #arr.copy()가 아님 arr쓸 pre_arr과 arr이 같은주소를 가르킴
        del arr[0:]             #so, 이부분에서 arr를 비울 시 pre_arr도 비워짐- 그래서else부분에서 인덱스에러뜸
        for z in range(0, j):
            if z == j-1:
                arr += [1]
                print(1)
            elif z == 0:
                print(1, end =' ')
                arr += [1]
            else:
                arr += [pre_arr[z-1]+pre_arr[z]]
                print("{}".format(arr[z]), end = ' ')
