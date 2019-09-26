class Solution(object):
    def countBits(self, num):
        arr = []
        for x in range(num+1):
            count = 0
            if x == 0:
                arr += [0]
                continue
            if(x & 1) == 1:
                arr += [1+arr[x>>1]]
            else:
                arr += [arr[x>>1]]
        return arr

a = Solution()
num = int(input())
print(a.countBits(num))
