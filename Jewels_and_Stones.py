class Solution(object):
    def numJewelsInStones(self, J, S):
        arr= [0] * 52
        real_count = 0
        
        for x in range(len(S)):
            if 65 <= ord(S[x]) <= 90:
                arr[ord(S[x])-65] += 1
            else:
                arr[ord(S[x])-71] += 1
                
        for x in range(len(J)):
            if 65 <= ord(J[x]) <= 90:
                real_count += arr[ord(J[x])-65]
            else:
                real_count += arr[ord(J[x])-71]
                
        return real_count
       
a = Solution()
J = 'aA'
S = "aAAbbbb"
print(a.numJewelsInStones(J,S))
