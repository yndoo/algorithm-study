import sys
myinput = sys.stdin.readline

S = myinput().strip()
T = myinput().strip()
res = 0

def mystr(S, T):
    global res
    flag = 0
    if S==T:
        res = 1
        return
    if len(T)<len(S):
        return
    if T[-1] == 'A':
        mystr(S,T[:len(T)-1])
    if T[0] == 'B':
        T = T[1:len(T)]
        mystr(S,T[::-1])

mystr(S, T)
print(res)