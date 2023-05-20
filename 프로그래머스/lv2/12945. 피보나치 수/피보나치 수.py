def solution(n):
    n0, n1 = 0, 1
    cnt=1
    while cnt<n:
        n0, n1 = n1, n0
        n1 = n1+n0
        cnt+=1
    return n1%1234567