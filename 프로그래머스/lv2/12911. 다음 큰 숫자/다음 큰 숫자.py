def solution(n):
    bin=""
    num=n
    while n>0:
        bin = str(n%2) + bin
        n=n//2
    cnt = bin.count("1")
    
    for i in range(num+1,1000001):
        bin=""
        j=i
        while i>0:
            bin = str(i%2) + bin
            i=i//2
        if bin.count("1")==cnt:
            return j
