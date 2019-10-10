class Solution(object):
    def longestCommonPrefix(self, strs):
        if len(strs) == 0: return ""
        count = 0
        for i in zip(*strs):
            a = set(i)
            if len(a) == 1:
                count += 1
            else: break
        return strs[0][:count]
                
a = Solution()
ll = ["flower", "flow", "flight"]
print(a.longestCommonPrefix(ll))
