import base64		#base64인코딩 디코딩 할수 있게 해줌줌
			#base64는 전송량의 33% 더 보낼 수 있음
t = int(input())	#아스키코드의 남는 1비트 처리가 컴마다 상이해서 좋음
for i in range(1,t+1):
    print("#%d" % i, end = ' ')
    s = input()
    s1 = base64.b64decode(s)	#디코드해줌 - 아스키로 바꿔줌
    print(s1.decode("UTF-8"))			#byte객체라는 표시 떼버리기	
