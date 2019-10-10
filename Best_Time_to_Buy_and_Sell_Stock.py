#DP사용
class Solution(object):
    def maxProfit(self, prices): 
        #예외 빈 배열이 들어오면 0 리턴
        if len(prices) == 0: return 0
        #사고 팔아서 가장 큰 값(리턴값)
        max_return = 0
        #배열을 돌면서 그때까지의 가장 작은 값을 넣어둠
        #처음에는 첫번째 요소를 넣어둠
        min_value = prices[0]

        """
        1.첫번째요소는 이미 min_value를 넣었으니 건너뛰고 시작함
        2.현 min_value보다 더 작은 수를 만나면 min_value에 넣음
        3.현 min_value보다 큰 수를 만나면 그 수-min_value가 max_return보다 크면 max_return에 넣음
        즉, 현재까지 나온 수중 가장 작은 수와 그 수 보다 큰수의 뺄셈이 가장 큰 수를 반환
        DP를 사용해서 푼건지 아니면 이 문제자체가 DP가 필요없이 O(n)것인지...
        """
        for x in range(1,len(prices)):
            if min_value > prices[x]:
                min_value = prices[x]
            else:
                if max_return < prices[x]-min_value:
                    max_return = prices[x]-min_value
        return max_return

#문제와 상관없음
a = Solution()
prices = [7,1,5,3,6,4]
print(a.maxProfit(prices))
