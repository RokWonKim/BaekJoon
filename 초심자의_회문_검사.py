#1989.초심자의 회문 검사
t = int(input())
for i in range(1, t+1):
    s = input()
    print("#%d" % i, end = ' ')
    count = 0							#회문이 아닌게 검증되면 1로 올림
    for j in range(0, len(s)//2):
        if s[j] != s[-(j+1)]:			#0에서 부터 점점증가하는것과 -1에서부터 점점 감소하는 인덱스의 값이 다르면 회문이아님
            print(0)					#홀수든 짝수든//2로 하면 됨 홀수일시 그 문장의 가운데 인덱스는 무엇이든 상관없음
            count = 1
            break
    if count == 0:					#회문이면 1
        print(1)
