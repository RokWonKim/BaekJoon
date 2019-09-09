t = int(input())
for i in range(1,t+1):
    print("#%d" % i,end = ' ')
    nums = input()
    nums = nums.split()
    nums = [int(x) for x in nums]		
    nums.sort()								#정렬
    del nums[0]								#가장 적은 수 삭제
    del nums[len(nums)-1]			#가장 큰 수 삭제 
    print( round(sum(nums)/len(nums)) ) #nums배열 합과 길이로 나누면 평균 소수점이 존재해야 하므로 / 썻고 round로 반올림
