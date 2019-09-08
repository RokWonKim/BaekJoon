t = int(input())
for i in range(1, t + 1):
    N = int(input())
    arr = []
    sentance = ""
    print("#%d" % i)
    for j in range(0, N):       #arr에 알파뱃과 숫자를 2차원 배열로 넣음
        Ciki = input()
        Ciki = Ciki.split(' ')
        arr += [Ciki]
    for j in range(0, N):       #알파뱃*숫자를 하나의 문장으로 만듬
        sentance += arr[j][0] * int(arr[j][1])
    print(sentance[0], end='')
    for j in range(1, len(sentance)):   #10개씩 출력
        if j % 10 == 0:
            print()
        print(sentance[j], end='')
    print()

