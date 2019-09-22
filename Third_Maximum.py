class Solution(object):
    def thirdMax(self, nums):
        count = 0
        max = 0
        nums.sort(reverse=True)
        for x in range(len(nums)):
            if max != nums[x]:
                count +=1
                max = nums[x]
            if count == 3:
                return max
        return nums[0]
    
a = Solution()
b = [1,1,3]
print(a.thirdMax(b));
