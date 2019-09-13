#1970.쉬운_거스름돈
t = int(input())
for i in range(1,t+1):
    money = int(input())
    print("#%d" % i)
    arr_money = [50000,10000,5000,1000,500,100,50,10]
    for j in range(0,8):
        print(money//arr_money[j], end = ' ')
        money = money%arr_money[j]
    print()
