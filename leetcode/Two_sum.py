nums = [3,2,4]
target = 6
index = 0
now = 0
for i in range(len(nums) - 1, -1, -1):
    now = nums.pop()
    for j in range(0, i):
        index = now+nums[j]
        if index == target:
            print(j, i)