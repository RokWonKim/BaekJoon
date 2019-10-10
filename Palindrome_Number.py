class Solution(object):
    def isPalindrome(self, x):
        if x >= 0 and str(x) == str(x)[::-1]: return True
        else: return False

s = Solution()
num = s.isPalindrome(121)
print(num)
