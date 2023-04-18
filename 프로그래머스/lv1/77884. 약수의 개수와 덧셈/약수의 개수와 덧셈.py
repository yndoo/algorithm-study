def solution(left, right):
    answer = 0
    lst=[]
    for i in range(1,40):
        if(i**2<=1000): lst.append(i**2)
    for x in range(left,right+1):
        if x in lst:
            answer-=x
        else:
            answer+=x
    return answer