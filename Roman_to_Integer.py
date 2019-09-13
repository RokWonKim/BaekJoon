class Solution(object):
    def romanToInt(self, s):
        sum = 0
        arr = {'V':5,'L':50,'D':500,'M':1000}	#사전으로 각 값 저장
        for i in range(len(s)):
            if s[i] == 'I':	#뒤에 나오는거 보고 -1이나 +1
                if i != len(s)-1 and (s[i+1] == 'V' or s[i+1] == 'X'): sum -= 1 
                else: sum +=1
            elif s[i] == 'X':	#뒤에 나오는거 보고 -10D이나 +10
                if i != len(s)-1 and (s[i+1] == 'L' or s[i+1] == 'C'): sum -= 10
                else: sum +=10
            elif s[i] == 'C':	#뒤에 나오는거 보고 -100이나 +100
                if i != len(s)-1 and (s[i+1] == 'D' or s[i+1] == 'M'): sum -= 100
                else: sum +=100
            else:
                sum += arr[s[i]]
        return sum

s = Solution()
print(s.romanToInt(input()))
