def solution(n):
    #경우의 수가 피보나치였다!
    n0, n1 = 1, 1
    for i in range(2,n+1):
        n1, n0 = n0+n1, n1
    return n1%1234567
'''
시간초과 - 백트래킹...
def solution(n):
    answer = 0
    entire=[]
    jumping(n,[],entire)
    return len(entire)%1234567

def jumping(n, lst, entire):
    if sum(lst)==n and lst not in entire:
        entire.append(lst)
        return True
    for d in range(1,3):
        if sum(lst)+d <= n:
            jumping(n,lst+[d],entire)
    return False
'''