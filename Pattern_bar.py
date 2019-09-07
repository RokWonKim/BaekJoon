t = int(input())
for i in range(1, t + 1):
    pattern = input()
    barstart = pattern[0]
    print("#%d" % i , end = ' ')
    for j in range(1, len(pattern) ):
        if pattern[j] == barstart:
            if len(pattern) > j+j-1 and str(pattern[0:j-1]) == str(pattern[j:j+j-1]):
                print(j)            # str() 붙여야 비교할 수 있음
                break
        elif j == len(pattern) - 1:
            print(1)
