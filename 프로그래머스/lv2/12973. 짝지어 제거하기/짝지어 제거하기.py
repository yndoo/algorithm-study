def solution(s):
    lst = list(s)
    stack=[]
    for chr in lst:
        if len(stack)>0 and chr==stack[-1]:
            stack.pop()
        else:
            stack.append(chr)
    if len(stack)==0:
        return 1
    else:
        return 0