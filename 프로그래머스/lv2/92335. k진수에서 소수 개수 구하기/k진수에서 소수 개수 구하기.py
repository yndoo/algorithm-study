def isprime(i):
    if i =='' or i=='1':
        return False
    i = int(i)
    for x in range(2,int(i**(0.5))+1):
            if i % x==0:
                return False
    return True
def solution(n, k):
    answer = 0
    #k 진수로 전환
    knum = ''
    while n>0:
        knum = str(n%k) + knum
        n = n//k
    #0 기준으로 split, 소수개수 세기
    for i in knum.split('0'):
        if isprime(i):
            answer+=1
        
    return answer