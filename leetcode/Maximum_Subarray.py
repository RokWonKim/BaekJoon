class Solution(object):
    def maxSubArray(self, nums):
        if len(nums) <= 1: return nums[0]
        
        arr = [0]*len(nums)
        max_return = nums[0]
        arr[0] = nums[0]
        for x in range(1,len(nums)):
            if arr[x-1]+nums[x] < 0:
                arr[x] = nums[x]
            else:
                if arr[x-1] <= 0: arr[x] = nums[x]
                else: arr[x] = arr[x-1]+nums[x]
            if max_return < arr[x]:
                max_return = arr[x]
        return max_return

a = Solution()
nums = [-2,1,-3,4,-1,2,1,-5,4]
print(a.maxSubArray(nums))
