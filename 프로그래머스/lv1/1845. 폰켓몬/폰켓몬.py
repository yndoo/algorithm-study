def solution(nums):
    N = len(nums) #폰켓몬 수
    types = len(set(nums)) #종류 수
    
    if N/2>=types:
        return types
    else:
        return N/2
