import sys
myinput = sys.stdin.readline

N, M = map(int, myinput().split())

def back(lst):
    if len(lst)==M:
        print(' '.join(map(str, lst)))
        return True
    for i in range(1,N+1):
        lst.append(i)
        back(lst)
        lst.pop()
    return False

back([])