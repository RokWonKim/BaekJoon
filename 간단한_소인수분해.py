#1945.간단한_소인수분해
for i in range(int(input())):
    N = int(input())
    arr = [0]*5
    mod = 2
    while N != 1:
        if (N%mod) == 0:
            if mod == 2: arr[0] += 1
            elif mod == 3: arr[1] +=1
            elif mod == 5: arr[2] +=1
            elif mod == 7: arr[3] +=1
            elif mod == 11: arr[4] +=1
            N //= mod
        else:
            mod += 1
    print("#%d" % (i+1), end = ' ')
    for z in arr:
        print(z,end = ' ')
    print()

# arr1 = [2,3,5,7,9]
# arr2 = [0] * 5
# for z in len(arr1):
#    while N%arr1[z] == 0:
#        arr2[z] += 1
#        N //= arr1[z]
#    if N==1: break
