def solution(s):
    cnt, zero, c = 0, 0, 0
    while s!="1":
        ze = s.count('0')   #단계별 0 개수
        zero+=ze    #누적 0 개수
        c = len(s)-ze   #단계별 1 개수
        strr=""
        while c>0:
            strr = str(c%2) + strr
            c = c//2
        cnt+=1
        s = strr

    return [cnt, zero]
