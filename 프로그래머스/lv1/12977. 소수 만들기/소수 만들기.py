def solution(nums):
    answer = 0
    prime=[] #소수 리스트
    nums.sort()

    for i in range(2,max(nums)*3-3):
        ispr=1
        for j in range(2,i):
            if i%j==0:
                ispr=0
                break
        if ispr == 1 : prime.append(i)  #조건문 밖 else도 가능..
    
    def back(lst):
        nonlocal answer
        if len(lst)==3:
            s = sum(lst)
            if s in prime:
                answer+=1
                return
        else:
            for i in nums:
                if len(lst)==0:
                    lst.append(i)
                    back(lst)
                    lst.pop()
                elif i not in lst and i > lst[-1]:
                    lst.append(i)
                    back(lst)
                    lst.pop()
        return
    back([])
    return answer

