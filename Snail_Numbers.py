def rigthgo(arr, N, num, col, row):                 #우측으로가기
    arr[col][row] = num
    if num >= N * N: return arr
    if row + 1 >= N or arr[col][row + 1] != 0:
        arr = downgo(arr, N, num + 1, col + 1, row) #표를 벗어나거나 다른숫자가 있으면 밑으로
    else:
        arr = rigthgo(arr, N, num + 1, col, row + 1)    #계속 우측으로 가면서 num 하나씩 올려주기 (재귀)
    return arr

def downgo(arr, N, num, col, row):                  #밑으로가기
    arr[col][row] = num
    if num >= N * N: return arr
    if col + 1 >= N or arr[col + 1][row] != 0:
        arr = leftgo(arr, N, num + 1, col, row - 1) #표를 벗어나거나 다른숫자가 있으면 왼쪽으로
    else:
        arr = downgo(arr, N, num + 1, col + 1, row) #계속 밑으로 가면서 num 하나씩 올려주기 (재귀)
    return arr

def upgo(arr, N, num, col, row):                    #위로가기
    arr[col][row] = num
    if num >= N * N: return arr
    if col - 1 >= N or arr[col - 1][row] != 0:      #표를 벗어나거나 다른숫자가 있으면 오른쪽으로
        arr = rigthgo(arr, N, num + 1, col, row + 1)
    else:
        arr = upgo(arr, N, num + 1, col - 1, row)   #계속 위로 가면서 num 하나씩 올려주기 (재귀)
    return arr

def leftgo(arr, N, num, col, row):                  #왼쪽으로가기
    arr[col][row] = num
    if num >= N * N: return arr
    if row - 1 >= N or arr[col][row - 1] != 0:      #표를 벗어나거나 다른숫자가 있으면 위로
        arr = upgo(arr, N, num + 1, col - 1, row)
    else:
        arr = leftgo(arr, N, num + 1, col, row - 1) #계속 아래로 가면서 num 하나씩 올려주기 (재귀)
    return arr

t = int(input())
for i in range(1, t + 1):
    N = int(input())
    print("#%d " % i)
    arr = []                # 빈 리스트 만들기
    num = 0
    for j in range(0, N):   # 빈 리스트안에 리스트 추가(2차원 리스트
        part_arr =[0] * N   # 0으로 초기화
        arr +=[part_arr]

    arr = rigthgo(arr, N, 1, 0, 0)  #2차원 리스트 완성해 주게 보내버리기
    for j in range(0, N):           # 2차원 리스트 출력
        for z in range(0, N):
            print(arr[j][z],end = ' ')
        print()

