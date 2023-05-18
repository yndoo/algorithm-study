def solution(s):
    cnt, zero, c = 0, 0, 0
    while 1:
        if s=="1": break
        ze = s.count('0')
        zero+=ze
        c = len(s)-ze
        strr=""
        while c>0:
            strr = str(c%2) + strr
            c = c//2
        cnt+=1
        s = strr

    return [cnt, zero]