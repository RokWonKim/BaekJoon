import copy

t = int(input())
arr = list()
pre_arr = list()
for i in range(1, t + 1):
    N = int(input())
    print("#{}".format(i))
    for j in range(1, N + 1):
        pre_arr = arr.copy()
        del arr[0:]
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
