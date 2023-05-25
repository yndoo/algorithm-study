def solution(n,a,b):
    answer = 0
    if a>b: a,b=b,a
    while True:
        answer+=1
        if a%2==1 and b-a==1:
            return answer
        
        if a%2!=0:
            a = a//2+1
        else: a = a//2
        if b%2!=0:
            b = b//2+1
        else: b= b//2
        
        