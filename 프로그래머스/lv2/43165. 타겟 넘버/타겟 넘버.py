def solution(numbers, target):
    answer = 0
    def myfun(i, num):
        nonlocal answer
        if i == len(numbers):
            if num==target: 
                answer+=1
            return 1
        myfun(i+1,num+numbers[i])
        myfun(i+1,num-numbers[i])
        return 1
    myfun(0,0)
    return answer