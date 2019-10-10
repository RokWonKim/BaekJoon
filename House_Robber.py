#DP사용
class Solution(object):
    def rob(self, nums):

        #nums만큼의 길이를 가진 배열 생성
        addsum = [0]*len(nums)
        
        #예외처리 해줌 - 빈 배열이거나 1개만 들어있으면 0또는 num[0]반환
        if len(nums) == 0: return 0
        elif len(nums) == 1: return nums[0]
        
        #nums배열의 길이 만큼 반복함 O(n)
        """
        intro - nums배열에서 얻은 값에 addsum에 들어가있는 값을 더해주어 addsum배열에 넣음

        1. index 0,1은 그냥 집어넣어 줌 근접한 집을 털면 안되므로index -2혹은 -3
           의 값을 사용해 현 index값에 더해줘야함 (-4부터는 -2 + -2 한 것과 같기 때문에 의미가 없음)
        2. index 2인 경우는 -2만 가능하기때문에 따로 elif구문 써줌
        3. 나머지는 현 인덱스에서 -2, -3인덱스를 각각  더해준 것 중 더 큰 값을 addsum[x]에 넣음
           ㄴbecause, addsum에는 어차피 nums 데이터(현재 인덱스의 전 인덱스까지)들을 더한 데이터가 들어가서 그 데이터를 이용
        4. 마지막은 가장 끝 인덱스와 그 바로 앞 인덱스를 비교하여 큰 값을 리턴
           ㄴ-2,-3한 값을 계속 더해주는 것이므로 가장 뒤의 두개를 비교해 줘야함 0과 -1을 비교하는 느낌
           """
        for x in range(len(nums)):

            if x == 0 or x == 1: addsum[x] = nums[x]
            elif x == 2: addsum[x] = nums[0] + nums[2]
            else:
                if nums[x]+addsum[x-2] > nums[x]+addsum[x-3]:
                    addsum[x] = nums[x]+addsum[x-2]
                else: addsum[x] = nums[x]+addsum[x-3]

        max = addsum[-1]
        if max < addsum[-2]: max = addsum[-2]
        return max
       
#내가 더해준 코드(필요없음)
a = Solution()
nums = [1,2,3,1]
print(a.rob(nums))
