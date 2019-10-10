#수도의 양 W / P = 1리터당 가격 / 기본요금 Q / R = 기본금최대리터 / S = 초과시1L당금액
for i in range(int(input())):
    P,Q,R,S,W = map(int,input().split())
    answer = 0
    if W<=R:
        if P*W > Q: answer = Q
        else: answer = P*W
    else:
        if P*W > Q+(W-R)*S: answer = Q+(W-R)*S
        else: answer = P*W
    print(f'#{i+1} {answer}')
