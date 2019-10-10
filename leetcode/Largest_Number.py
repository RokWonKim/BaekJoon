from functools import cmp_to_key
def compare(a,b):
    return (a+b>b+a) - (b+a>a+b)

class Solution:
    def largestNumber(self, nums):
        if len(nums) == 0: return ""
        elif max(nums) == 0: return "0"
        nums = sorted([str(x) for x in nums], key = cmp_to_key(compare), reverse = True)
        return "".join(nums)
        
a = Solution()
ll = [2,10]
print(a.largestNumber(ll))
