class Solution(object):
    def reverse(self, x):
        sign = 1
        if x < 0:           #들어온게 0보다 크면 부호 -1붙임
            sign = -1
            x *= sign
        elif x == 0: return 0        #0이면 0으로 반환

        arr = str(x)
        arr = arr[::-1]     #문자열 역순으로 바꾸기
        count = 0
        for i in range(0, len(arr)):    #앞에 0이 있으면 안되므로 처음부터 연속으로 0이 나오는 마지막 부분을 저장
            if arr[i] == '0': count += 1
            else: break

        if int(arr[count:]) > pow(2, 31) - 1: return 0   #32비트 초과되면 0반환
        return sign * int(arr[count:])  #부호 붙여서 반환

a = Solution()
print(a.reverse(7))
